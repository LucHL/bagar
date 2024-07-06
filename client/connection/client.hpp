/*
** EPITECH PROJECT, 2024
** B-YEP-400-STG-4-1-zappy-olaf.breitenbucher
** File description:
** client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_
    #include <iostream>
    #include <list>
    #include <unordered_map>
    #include <functional>
    #include <sstream>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>

class Client {
    public:
        Client() {};
        Client(int port, std::string ip);
        ~Client();

        bool connectClient();
        void receiveInfoFromServer();
        void sendMessage();
        void addToQueue(std::string message);
        void setPtrFunct();
        bool getConnectionFailed();

    private:
        bool _connectionFailed;
        int _socket;
        int _port;
        std::string _ip;
        struct sockaddr_in _addr;
        struct timeval _time;
        fd_set _readfd;
        fd_set _writefd;
        std::list<std::string> _messageQueue;
        std::unordered_map<std::string, std::function<void (std::istringstream &iss)>> _ptrFunct;
};

#endif /* !CLIENT_HPP_ */
