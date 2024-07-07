/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** Game
*/

#ifndef GAME_HPP_
    #define GAME_HPP_
    #include "raylib.h"
    #include "data/GlobalData.hpp"
    #include "scene/SceneManager.hpp"
    #include "scene/AScene.hpp"

class Game {
    public:
        Game();
        ~Game();

        void gameLoop();

    private:
};

#endif /* !GAME_HPP_ */
