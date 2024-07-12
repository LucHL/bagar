/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** AScene
*/

#ifndef ASCENE_HPP_
    #define ASCENE_HPP_
    #include "IScene.hpp"
    #include "../data/GlobalData.hpp"

class AScene : public IScene {
    public:
        AScene();
        ~AScene();

        void drawPlayer();
        void drawMap();
        void handleCamera();
        void draw3D();
        void draw2D();
        std::string handleKeyBoard();
        void beforeDrawing();
        void beforeMode();

    protected:
        Audio _music;
};

#endif /* !ASCENE_HPP_ */
