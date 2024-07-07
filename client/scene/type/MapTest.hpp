/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** MapTest
*/

#ifndef MAPTEST_HPP_
    #define MAPTEST_HPP_
    #include "../AScene.hpp"
    #include "../SceneManager.hpp"

class MapTest : public AScene {
    public:
        MapTest();
        ~MapTest();

        void drawPlayer() override;
        void drawMap() override;
        void handleCamera() override;
        void draw3D() override;
        void draw2D() override;
        void beforeDrawing() override;
        void beforeMode() override;

    private:
        void blockCursor();
};

#endif /* !MAPTEST_HPP_ */
