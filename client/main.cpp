/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** main
*/

#include "Game.hpp"

#ifdef _WIN32
#define OS_WINDOWS
#else
#define OS_LINUX
#endif

int main(int argc, char **argv)
{
    // int result;
    // #ifdef OS_WINDOWS
    //     result = std::system("maj.bat");
    //     std::cout << "Mise à jour réussie : OS Window" << std::endl;
    // #else
    //     std::system("chmod +x maj.sh");
    //     result = std::system("./maj.sh");
    //     std::cout << "Mise à jour réussie : OS Linux" << std::endl;
    // #endif
    // if (!result)
    //     std::cout << "Échec de la mise à jour" << std::endl;

    Game game;
    game.gameLoop();
    return 0;
}
