/* cliTCP.c - Exemplu de client TCP
   Trimite un nume la server; primeste de la server "Hello nume".

   Autor: Lenuta Alboaie  <adria@infoiasi.ro> (c)2009

*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

#define PORT 60000
#define LOCALHOST_IP "127.0.0.1"

bool write_message_to_socket(int socket_descriptor, string message)
{
    int size = message.size();
    if (-1 == write(socket_descriptor, &size, sizeof(size)))//scriem size-ul mai intai
        return false;
    if (-1 == write(socket_descriptor, message.data(), size))//scriem mesajul initial
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

bool parse_client_command(string &message)
{
    for (int i = 0; i < message.length(); i++)
        if (message[i] == ' ')
            return false;
    int last_index = message.length() - 1;//luam ultima pozitie
    while (message[last_index] == '\r' || message[last_index] == '\n')//cat timp ultima pozitie e e endline il stergem
    {
        message.pop_back();
        if (--last_index == 0)
            return false;
    }

    return true;
}

bool read_user_input_and_reply(char msg[100], string &message, int server_descriptor, string command_id, string text)
{
    do
    {
        bzero(msg, 100);
        printf("[client]Introduceti un %s:", text.c_str());
        fflush(stdout);
        read(0, msg, 100);
        message = msg;
    } while (!parse_client_command(message));
    message = command_id + message;
    if (!write_message_to_socket(server_descriptor, message))
    {
        perror("[client]Eroare la write() spre server.\n");
        return errno;
    }
    return true;
}

int main(int argc, char *argv[])
{
    int sd;			// descriptorul de socket
    struct sockaddr_in server;	// structura folosita pentru conectare 
    char msg[100];		// mesajul trimis

    ///* exista toate argumentele in linia de comanda? */
    //if (argc != 3)
    //{
    //    printf("[client] Sintaxa: %s <adresa_server> <port>\n", argv[0]);
    //    return -1;
    //}

    /* cream socketul */
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("[client] Eroare la socket().\n");
        return errno;
    }

    /* umplem structura folosita pentru realizarea conexiunii cu serverul */
    /* familia socket-ului */
    server.sin_family = AF_INET;
    /* adresa IP a serverului */
    server.sin_addr.s_addr = inet_addr(LOCALHOST_IP);
    /* portul de conectare */
    server.sin_port = htons(PORT);

    /* ne conectam la server */
    if (connect(sd, (struct sockaddr *) &server, sizeof(struct sockaddr)) == -1)
    {
        perror("[client]Eroare la connect().\n");
        return errno;
    }

    /* citirea mesajului */
    string message;
    if (!read_user_input_and_reply(msg, message, sd, "1","nume de ulizator"))//citim mesajul pentru "login", utilizatorul isi trece numele
        return errno;
    if (!read_user_input_and_reply(msg, message, sd, "2","nume de camera")) //citim mesajul pentru "join"
        return errno;

    while (true)
    {
        if (!read_message_from_socket(sd, message))//citim in permanenta ce ne da serverul
            return errno;
        char id = message[0];//lual id-ul comenzii
        if (message.length() > 1) //daca mai sunt caractere pe langa id
            message = message.substr(1, message.length() - 1);
        if (id == '0') //daca e id-ul "0" atunci doar afisam mesajul
            cout << message << endl;
        else if (id == '1') //la '1' utilizatorul trebuie sa si raspunda
        {
            cout << message << endl;
            if (!read_user_input_and_reply(msg, message, sd, "0","cuvant"))
                return errno;
        }
        else if(id=='2')
        {
            cout << message << endl;
            break;
        }
    }

    /* inchidem conexiunea, am terminat */
    close(sd);
}
