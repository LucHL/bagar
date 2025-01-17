/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** main
*/

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>

#define PORT 1234
#define MAX_CLIENTS 30
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int master_socket, addrlen, new_socket, client_socket[MAX_CLIENTS], max_clients = MAX_CLIENTS;
    int activity, i, valread, sd;
    int max_sd;
    struct sockaddr_in address;

    char buffer[BUFFER_SIZE]; // data buffer of 1K

    // set of socket descriptors
    fd_set readfds;

    // initialise all client_socket[] to 0 so not checked
    for (i = 0; i < max_clients; i++) {
        client_socket[i] = 0;
    }

    // create a master socket
    if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::perror("socket failed");
        std::exit(EXIT_FAILURE);
    }

    // set master socket to allow multiple connections
    int opt = 1;
    if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0) {
        std::perror("setsockopt");
        std::exit(EXIT_FAILURE);
    }

    // type of socket created
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind the socket to localhost port 8080
    if (bind(master_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::perror("bind failed");
        std::exit(EXIT_FAILURE);
    }
    std::cout << "Listener on port " << PORT << std::endl;

    // try to specify maximum of 3 pending connections for the master socket
    if (listen(master_socket, 3) < 0) {
        std::perror("listen");
        std::exit(EXIT_FAILURE);
    }

    // accept the incoming connection
    addrlen = sizeof(address);
    std::cout << "Waiting for connections..." << std::endl;
    while (1) {
        // clear the socket set
        FD_ZERO(&readfds);

        // add master socket to set
        FD_SET(master_socket, &readfds);
        max_sd = master_socket;

        // add child sockets to set
        for (i = 0; i < max_clients; i++) {
            // socket descriptor
            sd = client_socket[i];

            // if valid socket descriptor then add to read list
            if (sd > 0) {
                FD_SET(sd, &readfds);
            }

            // highest file descriptor number, need it for the select function
            if (sd > max_sd) {
                max_sd = sd;
            }
        }

        // wait for an activity on one of the sockets , timeout is NULL , so wait indefinitely
        activity = select(max_sd + 1, &readfds, nullptr, nullptr, nullptr);

        if ((activity < 0) && (errno != EINTR)) {
            std::cerr << "select error" << std::endl;
        }

        // if something happened on the master socket , then its an incoming connection
        if (FD_ISSET(master_socket, &readfds)) {
            if ((new_socket = accept(master_socket, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
                std::perror("accept");
                std::exit(EXIT_FAILURE);
            }

            // inform user of socket number - used in send and receive commands
            std::cout << "New connection, socket fd is " << new_socket << ", ip is : " << inet_ntoa(address.sin_addr)
                << ", port : " << ntohs(address.sin_port) << std::endl;

            // add new socket to array of sockets
            for (i = 0; i < max_clients; i++) {
                // if position is empty
                if (client_socket[i] == 0) {
                    client_socket[i] = new_socket;
                    std::cout << "Adding to list of sockets as " << i << std::endl;
                    break;
                }
            }
        }
        // TODO intercepter les ctrl + C & D
    }
    // else it's some IO operation on some other socket
    for (i = 0; i < max_clients; i++) {
        sd = client_socket[i];

        if (FD_ISSET(sd, &readfds)) {
            // Check if it was for closing , and also read the incoming message
            if ((valread = read(sd, buffer, BUFFER_SIZE)) == 0) {
                // Somebody disconnected , get his details and print
                getpeername(sd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
                std::cout << "Host disconnected, ip " << inet_ntoa(address.sin_addr) << ", port " << ntohs(address.sin_port)
                    << std::endl;

                // Close the socket and mark as 0 in list for reuse
                close(sd);
                client_socket[i] = 0;
            } else {
                // set the string terminating NULL byte on the end of the data read
                buffer[valread] = '\0';
                send(sd, buffer, std::strlen(buffer), 0);
            }
        }
    }

    return 0;
}
