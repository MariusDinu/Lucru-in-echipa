//codul pentru server inspirat de pe https://profs.info.uaic.ro/~computernetworks/files/NetEx/S9/servTcpCSel.c
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <fstream>
#include <vector>
using namespace std;

#define PORT 60000

ifstream g1("dictionary.txt");//de aici citim cuvintele permise
ifstream g2("config.txt");//de aici citim cati player sunt maxim intr-o camera (max_room_players)

int max_room_players;//cati jucatori au voie maxim intr-o camera
vector<string> word_dictionary;//cuvintele pe care au utlizatorii voie sa le foloseasca

void read_game_config()
{
    char buffer[100];//bufferul pentru a citi line cu linie
    g2.getline(buffer, 100); //citim  linie din g2 (singura linie) -> numarul maxim de jucatori
    max_room_players = atoi(buffer); // convertesc din sir de caractere in numar, numarul de jucatori

    while (g1.getline(buffer, 100))//citim cuvintele linie cu linie , un singur cuvant e scris pe o linie
    {
        if (buffer[strlen(buffer) - 1] == '\r' || buffer[strlen(buffer) - 1] == '\n')
            buffer[strlen(buffer) - 1] = '\0';
        if (buffer[strlen(buffer) - 1] == '\r' || buffer[strlen(buffer) - 1] == '\n')
            buffer[strlen(buffer) - 1] = '\0';
        word_dictionary.emplace_back(buffer);//adaug in vectorul de cuvinte permise cuvantul proaspat citit
    }
}

bool word_exists_in_word_dictionary(string word)//check if string existst in the dictionary
{
    for (int i = 0; i < word_dictionary.size(); ++i)
        if (word == word_dictionary[i])
            return true;
    return false;
}

bool is_pheasant_word(string player_word, string last_word)
{
    if (!word_exists_in_word_dictionary(player_word))
        return false;
    if (last_word.substr(last_word.size() - 3, 2) == player_word.substr(0, 2))//verific utlimele 2 litere daca sunt la fel ca primele 2 litere 
        return true;
    return false;
}

class GameRoom;//definim doar numele pentru a-l putea folosi in clasa PlayerData

bool write_message_to_socket(int socket_descriptor, string message);
bool read_message_from_socket(int socket_descriptor, string &message);

//clasa player in care vom tine informatiile pentru jucatorul curent
class PlayerData
{
private:
    string name; //numele jucatorului
    int player_socket; //socket-ul prin care comunica utilizatorul cu serverul
public:
    GameRoom *room = nullptr;
    PlayerData(string name, int player_socket) :name(name), player_socket(player_socket) { cout << "Created PlayerData(" << name << "," << player_socket << ")" << endl; } //cerem numele si socketul cand creem un player
    int get_socket() { return player_socket; }; // returnam socket-ul utilizatorului
    string get_name() { return name; }
    void send_message(int id, string message) //trimitem mesajul utilizatorului cu codul specific
    {
        if (id == -1 || id == 2)//daca am castigat sau pierdut iesim din joc
        {
            message = "2" + message;
            disconnect();
        }
        else
            message = (char)('0' + id) + message;
        if (message.length() == 1)
        {
            switch (id)
            {
            case 1: message = "introduce cuvantul\n"; break;
            case -1: message = "ai pierdut!\n"; break;
            case 2: message = "ai castigat!\n"; break;
            default:
                message = "salut!\n";
            }
        }

        if (!write_message_to_socket(player_socket, message))
        {
            cout << "Eroare la scrierea mesajului catre " << name;
            disconnect();
        }
        else
            cout << name << ": a primit comanda " << id << ": " << message << endl;
    }
    void respond(string message);
    void disconnect();
};

//clasa care se ocupa de organizarea jucatorilor
class GameRoom
{
private:
    string room_name;
    vector<PlayerData*> players;//vectorul de jucatori care joaca momemntan
    bool started_game = false;
    PlayerData *expected_player = nullptr;
    bool waiting_first_letter = true;
    bool finished_game = false;
    string last_message = "";
public:
    GameRoom(string room_name) : room_name(room_name) { cout << "Created room: " << room_name << " " << endl; }
    bool is_finished() { return finished_game; }
    string get_name() { return room_name; };
    void add_player(PlayerData *player)
    {
        if (started_game == true)//jocul a inceput deja, nu mai putem adauga jucatori
        {
            player->send_message(1, "Masa este plina deja, incearca alta!");
            cout << "Utilizatorul " << player->get_name() << "a incercat sa intre la maasa " << room_name << " dar e plina deja";
            return;
        }
        players.emplace_back(player); player->room = this;
        string message = "server: Jucatorul " + player->get_name() + " s-a alaturat mesei " + room_name;
        broadcast_message(-1, 0, message);
        cout << message << endl;
        if (get_players_number() == max_room_players)//s-a umplut camera
        {
            started_game = true;//incepem jocul
            broadcast_message(-1, 0, "A inceput jocul!");
            cout << "A inceput jocul in camera " << room_name << "!" << endl;
            update_expected_player();//a inceput, actualizam ce jucator trebuie sa spuna ceva
        }
    } // adaugam jucatorul curent in camera de joc
    int get_player_index(int player_socket)
    {
        for (int i = 0; i < players.size(); ++i)//parcugem lista jucatorilor si cautam jucatorul cu socket-ul cautat
            if (players[i]->get_socket() == player_socket) //cand am gassit jucatorul
                return i; //cand am gasit jucatorul returnam id-ul lui
        return -1; //dac 
    }
    void send_player_command(int player_socket, int id, string message) //intoarcem clasa jucatorului curent pentru a-i putea trimite vreun mesaj sau pentru a-l da afara
    {
        int i = get_player_index(player_socket);//luam index-ul jucatorului
        if (i == -1) //daca e -1 inseamna ca nu am gasit jucatoru
            return;//ne oprim aici daca nu am gasit jucatorul

        players[i]->send_message(id, message);//trimitem mesajul jucatorului cu id-ul specific
        if (id == -1 || id == 2) //pentru cazurile cand a castigat sau a pierdut este dat afara
            players.erase(players.begin() + i); //dam jucatorul afara (este scos si din lista jucatorilor ascultati)
    }
    void disconnect(int player_socket) //cand s-a deconectat utilizatorul
    {
        int i = get_player_index(player_socket);//luam index-ul jucatorului
        if (i == -1) //daca e -1 inseamna ca nu am gasit jucatoru
            return;//ne orpim aici daca nu am gasit jucatorul
        if (started_game && players[i] == expected_player)//daca a inceput jocul si iese jucatorul care trebuie sa spuna cuvantul
            update_expected_player();//actualizam ce utilizator trebuie sa spuna cuvantul
        cout << "Jucatorul " << players[i]->get_name() << " a iesit de la masa!";
        players.erase(players.begin() + i); //il scoatem din lista
    }
    void broadcast_message(int sender_socket, int id, string message)//trimite tutoror jucatorilor mesajul cu exceptia celui curent (broadcast = trimite mesajul la toti)
    {
        for (auto& player : players) //parcugem lista jucatorilor
        {
            if (player->get_socket() != sender_socket)//daca nu este jucatorul curent (are alt socket "!="))
                player->send_message(id, message); //trimitem mesajul mai departe
        }
    }
    int get_players_number() { return players.size(); }//returnez cati playeri sunt in jocul curent
    void update_expected_player()//ce jucator trebuie sa spuna cuvantul
    {
        if (!expected_player)//daca nu a fost selectat pana acum un jucator, se alge primul
            expected_player = players[0];
        else//daca s-a ales deja un jucator inseamna ca cel care vrea sa iasa e cel care trebuie sa spuna cuvantul asa ca il actualizam
        {
            int player_index = get_player_index(expected_player->get_socket());
            if (player_index == -1)
                return;
            if (player_index + 1 < players.size())
                expected_player = players[player_index + 1];
            else
                expected_player = players[0];
        }
        expected_player->send_message(1, "Este randul tau!");
    }
    void restart_game()
    {
        if (players.size() == 1)
        {
            finished_game = true;
            broadcast_message(-1, 2, "Ai castigat!");
            return;
        }
        last_message.clear();
        waiting_first_letter = true;
        broadcast_message(-1, 0, "S-a restartat jocul!");
        update_expected_player();
    }
    void got_response(PlayerData *player, string message) //mesajul primit de jucator
    {
        if (player != expected_player)
        {
            cout << "Server: " << player->get_name() << " nu este randul tau!" << endl;
            return;
        }
        if (message[0] == '0')//ar trebuie sa fie 0 pe prima poztiei doar pentru un mesaj simlu de la jucator
        {
            message = message.substr(1, message.length() - 1);//stergem '0'-ul de la inceput
            if (last_message.size() && !word_exists_in_word_dictionary(message)) // daca e primul cuvant ales putem folosi orice, nu neaprat din dictionar
            {
                player->send_message(-1, "Cuvant invalid");
                restart_game();
                return;
            }
            if (waiting_first_letter)
            {
                if (last_message.size() == 0)//nu s0a ales inca prima litera
                {
                    message = message.substr(0, 1);
                    last_message = message;
                    broadcast_message(player->get_socket(), 0, player->get_name() + ": " + message);
                    update_expected_player();
                    return;
                }
                else //s-a ales prima litera
                {
                    waiting_first_letter = false;
                    if (message[0] != last_message[0])
                    {
                        player->send_message(-1, "Cuvant invalid");
                        restart_game();
                    }
                    else
                    {
                        update_expected_player();
                    }
                }
            }
            else
            {
                if (!word_exists_in_word_dictionary(message))
                {
                    player->send_message(-1, "Cuvant invalid");
                    restart_game();
                }
                else
                    update_expected_player();
            }
        }
        else
            player->send_message(1, "Mesaj invalid!");
    }
};

//jocurile sunt retinute dupa nume, cand este creat un joc acesta este memorat dupa nume
//de exemplu, daca un utilizator vrea sa dea join la un joc, daca acesta nu exista acel joc va fi creat mai intai apoi va putea intra si el
//cand se termina un joc, jocul este sters
map<string, GameRoom*> gameRooms;
//datele jucatorului sunt stocate in PlayerData, daca el nu a dat login nu apare in map-ul playerData, la fel si daca este dat afara
//cand utilizatorul este dat afara sau se deconecteaza va fi dat afara
map<int, PlayerData*> playerData;

//functia din interorul clasei PlayerData in care utilizatorul trimite raspunsul in camera
void PlayerData::respond(string message)
{
    if (room)//daca este deja intr-un room
        room->got_response(this, message);//trimite mesajul in camera
    else if (message[0] == '2')
    {
        string name = message.substr(1, message.length() - 1);//luam numele, ignoram primul caracter care e id-ul
        auto room_it = gameRooms.find(name);//room iterator
        if (room_it != gameRooms.end())//camera exista deja
            (*room_it).second->add_player(this);//incercam sa adaugam jucatorul in camera de joc
        else//daca nu exista camera de joc
        {
            GameRoom *room = new GameRoom(name);//creez camera de joc cu numele dat de jucator
            room->add_player(this); //adaug jucatorul in camera de joc
            gameRooms[name] = room; //anunt ca s-a creat camera cu acel nume
        }
    }
}
//functia de deconectare a playerului curent
void PlayerData::disconnect()
{
    if (room)//daca este deja intr-un room
    {
        room->disconnect(player_socket);
        if (room->is_finished())
        {
            string room_name = room->get_name();
            auto room_it = gameRooms.find(room_name);//room iterator
            gameRooms.erase(room_it);
            delete room;
        }
    }
    auto it = playerData.find(player_socket);
    if (it != playerData.end())//daca am gasit ceva
        playerData.erase(it);
    cout << "S-a deconectat " << name<<endl;
}

void analyze_player_response(int player_socket, string message)//am folosit mesajul '9'pentru a hardcoda disconnect-ul
{
    auto playerData_iterator = playerData.find(player_socket);
    if (playerData_iterator == playerData.end())//nu am gasit datele utilizatorului
    {
        if (message[0] != '1')//we ignore the message
            return;
        string name = message.substr(1, message.length() - 1);//luam numele, ignoram primul caracter care e id-ul
        PlayerData *player = new PlayerData(name, player_socket); //creem o noua instanta de PlayerData
        playerData[player_socket] = player; //salvam datele jucatorului
        return;//ne oprim aici pentru cazul curennt
    }
    else if (message[0] == '9')
        playerData_iterator->second->disconnect();
    else
        //daca am ajuns aici inseamna ca am gasit datele pentru player
        (*playerData_iterator).second->respond(message);//raspundem jucatorului
}

int main()
{
    read_game_config();
    struct sockaddr_in server;	/* structurile pentru server si clienti */
    struct sockaddr_in from;
    fd_set readfds;		/* multimea descriptorilor de citire */
    fd_set actfds;		/* multimea descriptorilor activi */
    struct timeval tv;		/* structura de timp pentru select() */
    int sd, client;		/* descriptori de socket */
    int optval = 1; 			/* optiune folosita pentru setsockopt()*/
    int fd;			/* descriptor folosit pentru
                     parcurgerea listelor de descriptori */
    int nfds;			/* numarul maxim de descriptori */
    int len;			/* lungimea structurii sockaddr_in */

    /* creare socket */
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("[server] Eroare la socket().\n");
        return errno;
    }

    /*setam pentru socket optiunea SO_REUSEADDR */
    setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    /* pregatim structurile de date */
    bzero(&server, sizeof(server));

    /* umplem structura folosita de server */
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);

    /* atasam socketul */
    if (bind(sd, (struct sockaddr *) &server, sizeof(struct sockaddr)) == -1)
    {
        perror("[server] Eroare la bind().\n");
        return errno;
    }

    /* punem serverul sa asculte daca vin clienti sa se conecteze */
    if (listen(sd, 5) == -1)
    {
        perror("[server] Eroare la listen().\n");
        return errno;
    }

    /* completam multimea de descriptori de citire */
    FD_ZERO(&actfds);		/* initial, multimea este vida */
    FD_SET(sd, &actfds);	/* includem in multime socketul creat */

    tv.tv_sec = 1;		/* se va astepta un timp de 1 sec. */
    tv.tv_usec = 0;

    /* valoarea maxima a descriptorilor folositi */
    nfds = sd;

    printf("[server] Asteptam la portul %d...\n", PORT);
    fflush(stdout);

    /* servim in mod concurent clientii... */
    while (1)
    {
        /* ajustam multimea descriptorilor activi (efectiv utilizati) */
        bcopy((char *)&actfds, (char *)&readfds, sizeof(readfds));

        /* apelul select() */
        if (select(nfds + 1, &readfds, NULL, NULL, &tv) < 0)
        {
            perror("[server] Eroare la select().\n");
            return errno;
        }
        /* vedem daca e pregatit socketul pentru a-i accepta pe clienti */
        if (FD_ISSET(sd, &readfds))
        {
            /* pregatirea structurii client */
            len = sizeof(from);
            bzero(&from, sizeof(from));

            /* a venit un client, acceptam conexiunea */
            client = accept(sd, (struct sockaddr *) &from, (socklen_t*)&len);

            /* eroare la acceptarea conexiunii de la un client */
            if (client < 0)
            {
                perror("[server] Eroare la accept().\n");
                continue;
            }

            if (nfds < client) /* ajusteaza valoarea maximului */
                nfds = client;

            /* includem in lista de descriptori activi si acest socket */
            FD_SET(client, &actfds);
        }
        /* vedem daca e pregatit vreun socket client pentru a trimite raspunsul */
        for (fd = 0; fd <= nfds; fd++)	/* parcurgem multimea de descriptori */
        {
            /* este un socket de citire pregatit? */
            if (fd != sd && FD_ISSET(fd, &readfds))
            {
                string message;
                if (!read_message_from_socket(fd, message))
                {
                    analyze_player_response(fd, "99");
                    printf("[server] S-a deconectat clientul cu descriptorul %d.\n", fd);
                    fflush(stdout);
                    close(fd);		/* inchidem conexiunea cu clientul */
                    FD_CLR(fd, &actfds);/* scoatem si din multime */
                }
                else
                    analyze_player_response(fd, message);
            }
        }			/* for */
    }				/* while */
}				/* main */

bool write_message_to_socket(int socket_descriptor, string message)
{
    int size = message.size();
    if (0 >= write(socket_descriptor, &size, sizeof(size)))//scriem size-ul mai intai
        return false;
    if (0 >= write(socket_descriptor, message.data(), size))//scriem mesajul initial
        return false;
    return true;
}
bool read_message_from_socket(int socket_descriptor, string &message)
{
    int size;
    char buffer[10000];
    if (-1 == read(socket_descriptor, &size, sizeof(size)))//scriem size-ul mai intai
        return false;
    if (-1 == read(socket_descriptor, buffer, size))//scriem mesajul initial
        return false;
    buffer[size] = '\0';
    message = buffer;
    return true;
}