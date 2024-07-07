/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** main
*/

#include "Game.hpp"

int main(int argc, char **argv)
{
    // std::system("chmod +x maj.sh");
    // int result = std::system("./maj.sh");

    // if (result == 0)
    //     std::cout << "Mise à jour réussie" << std::endl;
    // else
    //     std::cout << "Échec de la mise à jour" << std::endl;

    Game game;
    game.gameLoop();
    return 0;
}
