/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
    #define ISCENE_HPP_
    #include "raylib.h"
    #include <iostream>
    #include "../objects/Audio.hpp"
    #include <vector>

class IScene {
    public:
        virtual ~IScene() = default;
        
        virtual void drawPlayer() = 0;
        virtual void drawMap() = 0;
        virtual void handleCamera() = 0;
        virtual void draw3D() = 0;
        virtual void draw2D() = 0;
        virtual std::string handleKeyBoard() = 0;
        virtual void beforeDrawing() = 0;
        virtual void beforeMode() = 0;
};

#endif /* !ISCENE_HPP_ */
