#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstdlib>
#include <fcntl.h>
#include <cstdio>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <ctime>
#include <sys/socket.h>
#include <string>
using namespace std;
//caut fisierul "fisier"
string cauta_recursiv(string cale, string fisier)
{
    if (cale.length() == 0)
        return "";
    DIR *folder_curent;
    struct dirent *rdir;
    folder_curent = opendir(cale.c_str()); //deschid folder 
    if (folder_curent == 0)//eroare, nu l-am putut deschide
        return "";
    string result = "";

    rdir = readdir(folder_curent);//citesc din folder
    while (rdir)
    {
        string current_file = rdir->d_name; //nume fisier
        if (current_file == fisier)
        {
            result = cale + "/" + current_file; //formam noua cale
            break;
        }
        else if (current_file != "." && current_file != "..") //scot fisierele incluse peste tot "." si ".."
        {
            current_file = cale + "/" + current_file; //formam noua cale
            result = cauta_recursiv(current_file, fisier);
            if (result != "")
                break;

        }

        rdir = readdir(folder_curent);//citesc din folder   
    }
    closedir(folder_curent);
    return result;
}

string myfind(string cale, string fisier)
{
    string result = cauta_recursiv(cale, fisier);
    if (result != "")
    {
        struct stat st;//pentru informatii despre fisier
        if (stat(result.c_str(), &st) == 0)
        {
            result = "Locatie: " + result + "\n";//luate din linux din pagina de "man stat"
            result += "Stare schimbata ultima data:";
            result += ctime(&st.st_ctime);
            result += "\n";
            result += "Ultimului acces in fisier:";
            result += ctime(&st.st_atime);
            result += "\n";
            result += "Data modificarii:";
            result += ctime(&st.st_mtime);
            result += "\n";

            string permisiuni; /* aici vom construi forma simbolica pentru permisiunile fisierului - LUAT DIN LABORATORUL DE SO */
            if (S_IRUSR & st.st_mode)
                permisiuni.append("r");
            else
                permisiuni.append("-");
            if (S_IWUSR & st.st_mode)
                permisiuni.append("w");
            else
                permisiuni.append("-");
            if (S_IXUSR & st.st_mode)
                permisiuni.append("x");
            else
                permisiuni.append("-");
            if (S_IRGRP & st.st_mode)
                permisiuni.append("r");
            else
                permisiuni.append("-");
            if (S_IWGRP & st.st_mode)
                permisiuni.append("w");
            else
                permisiuni.append("-");
            if (S_IXGRP & st.st_mode)
                permisiuni.append("x");
            else
                permisiuni.append("-");
            if (S_IROTH & st.st_mode)
                permisiuni.append("r");
            else
                permisiuni.append("-");
            if (S_IWOTH & st.st_mode)
                permisiuni.append("w");
            else
                permisiuni.append("-");
            if (S_IXOTH & st.st_mode)
                permisiuni.append("x");
            else
                permisiuni.append("-");
            permisiuni.append("\n");

            result += "Permisiuni: ";
            result += permisiuni;
        }
        else
            result = "Locatie: " + result + ", fail stat";

    }
    else
        result = "Nu a putut fi gasit!\n";

    return result;
}

string mystat(string cale)
{
    string result;
    struct stat st;//pentru informatii despre fisier
    if (stat(cale.c_str(), &st) != 0)
        result = "Eroare la stat!\n";
    else
    {
        result += "File type: ";
        switch (st.st_mode & S_IFMT) {//luat din "man stat"
        case S_IFBLK:  result += "block device\n";            break;
        case S_IFCHR:  result += "character device\n";        break;
        case S_IFDIR:  result += "directory\n";               break;
        case S_IFIFO:  result += "FIFO/pipe\n";               break;
        case S_IFLNK:  result += "symlink\n";                 break;
        case S_IFREG:  result += "regular file\n";            break;
        case S_IFSOCK: result += "socket\n";                  break;
        default:       result += "unknown?\n";                break;
        }

        result += "I-node number ";
        result += to_string(st.st_ino);
        result += " \n";

        result += "Mode ";
        result += to_string(st.st_mode);
        result += " \n";

        result += "Link count ";
        result += to_string(st.st_nlink);
        result += " \n";

        result += "File size ";
        result += to_string(st.st_size);
        result += " \n";

        result += "Blocks allocated ";
        result += to_string(st.st_blocks);
        result += " \n";
    }
    return result;
}

bool login(string nume)
{
    ifstream f("/root/rc/users.txt");
    char line[100];
    while (f.getline(line, 100))
    {
        string result = line;
        result.erase(result.end() - 1);//sterge \r de la final
        if (nume == result)
            return true;
    }
    return false;
}

int main()
{
   
    pid_t fiu;
    //pipe-uri -> pipe intern
    int pipe1[2];//parinte la fiu
    int pipe2[2];//fiu la parinte


    int result = pipe(pipe1);
    if (result == -1)
    {
        printf("ERR! pipe1");
        return 0;
    }
    result = pipe(pipe2);
    if (result == -1)
    {
        printf("ERR! pipe1");
        return 0;
    }

    //fifo - pipe extern
    remove("fifo.fif");//sterg fifo-ul (pot exista probleme cand incerc sa-l creez daca nu-l sterg
    result = mkfifo("fifo.fif", 0666);
    if (result == -1)
    {
        printf("ERR! fifo");
        return 0;
    }
    int fifo = open("fifo.fif", O_RDWR);

    //sockets
    int sockets[2];//parintele scrie in socket[1], citeste din socket[0]
    result = socketpair(AF_UNIX, SOCK_STREAM, 0, sockets);
    if (result < 0)
    {
        printf("ERR! socket");
        return 0;
    }
    bool logat = false;
    while (true)
    {
        fiu = fork();
        if (fiu == -1)
        {
            printf("fork! err");
            return 0;
        }

        if (fiu == 0)//fiu
        {
            char comanda[100];
            int lungime_comanda;
            int canal_folosit;

            result = read(sockets[0], &canal_folosit, sizeof(canal_folosit));
            if (result == -1)
            {
                printf("ERR! read socket");
                break;
            }
            //cout << canal_folosit;
            if (canal_folosit == 0) //pipe
            {
                //trimitem lungimea comenzii
                result = read(pipe1[0], &lungime_comanda, sizeof(lungime_comanda));
                if (result == -1)
                {
                    printf("ERR! write pipe");
                    break;
                }

                //trimitem comanda
                result = read(pipe1[0], comanda, lungime_comanda);
                if (result == -1)
                {
                    printf("ERR! write pipe");
                    break;
                }
            }
            else //fifo
            {
                result = read(fifo, &lungime_comanda, sizeof(lungime_comanda));
                if (result == -1)
                {
                    printf("ERR! write fifo");
                    break;
                }

                //trimitem comanda
                result = read(fifo, comanda, lungime_comanda);
                if (result == -1)
                {
                    printf("ERR! write fifo");
                    break;
                }
            }
            comanda[lungime_comanda] = NULL;
            //cout << comanda;
            string result_string = "";
            string comanda_string = comanda;
            int spatii = 0;
            for (int i = 0; i < comanda_string.length(); ++i)
                if (comanda_string[i] == ' ')
                    spatii += 1;
			if (spatii > 2)
			{
				result_string = "Comanda invalida!\n";
				spatii = -2;
			}
            int locatie_spatiu = (int)comanda_string.find_first_of(' ');
            string comanda_efectiva = comanda_string.substr(0, locatie_spatiu);
            string parametru = "";
			
            if (locatie_spatiu != -1) //impartim dupa primul spatiu
                parametru = comanda_string.substr(locatie_spatiu + 1, comanda_string.length() - locatie_spatiu - 1);
            if (locatie_spatiu == -1 && comanda_efectiva == "quit")
            {
                exit(12);
            }
            if (spatii == 1)
            {
                if (comanda_efectiva == "login")
                {
                    bool res = login(parametru);
                    if (res == true)
                    {
                        logat = true;
                        exit(13);
                    }
                    else
                        result_string = "logare esuata!\n";
                }
                else if (comanda_efectiva == "mystat")
                {
                    if (logat == false)
                        result_string = "Nu sunteti logat!\n";
                    else
                        result_string = mystat(parametru);
                }
            }
            else if (spatii == 2 && comanda_efectiva == "myfind")
            {
                if (logat == false)
                    result_string = "Nu sunteti logat!\n";
                else
                {
                    locatie_spatiu = (int)parametru.find_first_of(' ');
                    string parametru_2 = parametru.substr(locatie_spatiu + 1, parametru.length() - locatie_spatiu - 1);
                    parametru = parametru.substr(0, locatie_spatiu);
                    result_string = myfind(parametru, parametru_2);
                }
            }
            else
                result_string = "Comanda \"" + comanda_string + "\" nu este recuonscuta\n";

            lungime_comanda = result_string.length();
            result = write(sockets[1], &lungime_comanda, sizeof(lungime_comanda));
            if (result == -1)
            {
                printf("ERR! write socket");
                break;
            }

            result = write(sockets[1], result_string.data(), lungime_comanda);
            if (result == -1)
            {
                printf("ERR! write socket");
                break;
            }
            exit(10);
        }
        else//parinte
        {
            char comanda[100];
            cout << "Introdu comanda: ";
            cin.getline(comanda, 100);
            string comanda_string = comanda;
            int lungime_comanda = comanda_string.length();
            int canal_folosit = 1;
            if (comanda_string.length() > 7 && comanda_string.substr(0, 7) == "myfind")
                canal_folosit = 0;
            else
                canal_folosit = 1;

            //trimitem canalul
            result = write(sockets[1], &canal_folosit, sizeof(canal_folosit));
            if (result == -1)
            {
                printf("ERR! write socket");
                break;
            }

            if (canal_folosit == 0) //pipe
            {
                //trimitem lungimea comenzii
                result = write(pipe1[1], &lungime_comanda, sizeof(lungime_comanda));
                if (result == -1)
                {
                    printf("ERR! write pipe");
                    break;
                }

                //trimited comanda
                result = write(pipe1[1], comanda_string.data(), lungime_comanda);
                if (result == -1)
                {
                    printf("ERR! write pipe");
                    break;
                }
            }
            else //fifo
            {
                result = write(fifo, &lungime_comanda, sizeof(lungime_comanda));
                if (result == -1)
                {
                    printf("ERR! write fifo");
                    break;
                }

                //trimited comanda
                result = write(fifo, comanda_string.data(), lungime_comanda);
                if (result == -1)
                {
                    printf("ERR! write fifo");
                    break;
                }
            }

            int cod_terminare;
            wait(&cod_terminare);
            if (WIFEXITED(cod_terminare))
            {
                cod_terminare >>= 8;
                if (cod_terminare == 12)//quit
                {
                    printf("Programul s-a terminat cu succes!\n");
                    return 0;
                }
                else if (cod_terminare == 13)//login
                {
                    logat = true;
                    cout<<"V-ati logat cu succes!\n";
                }
                else
                {
                    result = read(sockets[0], &lungime_comanda, sizeof(lungime_comanda));
                    if (result == -1)
                    {
                        printf("ERR! read socket");
                        break;
                    }
                    char raspuns[10000];
                    result = read(sockets[0], raspuns, lungime_comanda);
                    if (result == -1)
                    {
                        printf("ERR! read socket");
                        break;
                    }
                    raspuns[lungime_comanda] = NULL;
                    cout << raspuns;
                }
                //sleep(1);
            }
        }
    }


    close(sockets[0]);
    close(sockets[1]);
    close(fifo);
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[10]);
    close(pipe2[1]);
    //exemple
    //login vasile -> fail
    //login gaga -> merge
    //myfind /root/projects/t/sal ex3.c
    //mystat /root/projects/t/sal/ex3.c
    //quit
    //string res = myfind("/root/projects/t/sal", "ex3.c");
    //string res2 = mystat("/root/projects/t/sal/ex3.c");

    return 0;
}
