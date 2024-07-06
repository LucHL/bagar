/*
** EPITECH PROJECT, 2024
** B-YEP-400-STG-4-1-zappy-olaf.breitenbucher
** File description:
** client
*/

#include "client.hpp"

Client::Client(int port, std::string ip) : _port(port), _ip(ip)
{
    _socket = 0;
    if (!connectClient())
        return;
    setPtrFunct();
}

Client::~Client()
{
    close(_socket);
}

void Client::setPtrFunct()
{
    // _ptrFunct["msz"] = [this](std::istringstream &iss){ setMapSize(iss); };
    // _ptrFunct["bct"] = [this](std::istringstream &iss){ setContentOfTile(iss); };
    // _ptrFunct["tna"];
    // _ptrFunct["pnw"] = [this](std::istringstream &iss){ createPlayer(iss); };
    // _ptrFunct["ppo"] = [this](std::istringstream &iss){ setPosPlayer(iss); };
    // _ptrFunct["plv"] = [this](std::istringstream &iss){ setLevel(iss); };
    // _ptrFunct["pin"] = [this](std::istringstream &iss){ getInventory(iss); };
    // _ptrFunct["pex"];
    // _ptrFunct["pbc"] = [this](std::istringstream &iss){ broadcast(iss); };
    // _ptrFunct["pic"] = [this](std::istringstream &iss){ setIncantation(iss); };
    // _ptrFunct["pie"] = [this](std::istringstream &iss){ endIncantation(iss); };
    // _ptrFunct["pfk"];
    // _ptrFunct["pdr"];
    // _ptrFunct["pgt"];
    // _ptrFunct["pdi"] = [this](std::istringstream &iss){ playerDeath(iss); };
    // _ptrFunct["enw"] = [this](std::istringstream &iss){ addEgg(iss); };
    // _ptrFunct["ebo"] = [this](std::istringstream &iss){ connectionPlayerEgg(iss); };
    // _ptrFunct["edi"] = [this](std::istringstream &iss){ EggDeath(iss); };
    // _ptrFunct["sgt"] = [this](std::istringstream &iss){ getFrequence(iss); };
    // _ptrFunct["seg"];
    // _ptrFunct["smg"] = [this](std::istringstream &iss){ getMsgFromServeur(iss); };
    // _ptrFunct["suc"];
    // _ptrFunct["sbp"];
}

bool Client::getConnectionFailed()
{
    return _connectionFailed;
}

bool Client::connectClient()
{
    if ((_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error." << std::endl;
        _connectionFailed = true;
        return false;
    }

    _addr.sin_family = AF_INET;
    _addr.sin_port = htons(_port);

    if (inet_pton(AF_INET, _ip.c_str(), &_addr.sin_addr) <= 0) {
        std::cerr << "Invalid IP." << std::endl;
        _connectionFailed = true;
        return false;
    }
    if (connect(_socket, (struct sockaddr *)&_addr, sizeof(_addr)) < 0) {
        std::cerr << "Connection Failed." << std::endl;
        _connectionFailed = true;
        return false;
    }
    return true;
}

void Client::addToQueue(std::string message)
{
    message += "\n";
    _messageQueue.push_front(message);
}

void Client::sendMessage()
{
    if (FD_ISSET(_socket, &_writefd) && !_messageQueue.empty()) {
        std::string message = _messageQueue.back();
        send(_socket, message.c_str(), message.length(), 0);
        _messageQueue.pop_back();
    }
}

void Client::receiveInfoFromServer()
{
    std::string str;
    // char buffer[1024] = {0};

    FD_ZERO(&_readfd);
    FD_ZERO(&_writefd);

    FD_SET(STDIN_FILENO, &_readfd);
    FD_SET(STDIN_FILENO, &_writefd);
    FD_SET(_socket, &_readfd);
    FD_SET(_socket, &_writefd);

    _time.tv_sec = 0;
    _time.tv_usec = 1000;

    int activity = select(FD_SETSIZE, &_readfd, &_writefd, NULL, &_time);

    if (activity == -1) {
        std::cerr << "Select error." << std::endl;
        return;
    }

    sendMessage();

    // if (FD_ISSET(_socket, &_readfd)) {
    //     int len = read(_socket, buffer, sizeof(buffer) - 1);
    //     std::istringstream iss(buffer);

        // while (std::getline(iss, str)) {
        //     std::istringstream issw(str);
        //     issw >> str;
        //     if (_ptrFunct.contains(str)) {
        //         _ptrFunct[str](issw);
        //         // if (str != "bct")
        //         //     std::cout << "server [" << str << "]" << std::endl;
        //     }
        // }
    // }
}
