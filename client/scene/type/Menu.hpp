/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_
    #include "../AScene.hpp"
    #include "../SceneManager.hpp"

class Menu : public AScene {
    public:
        Menu();
        ~Menu();

        void drawPlayer() override;
        void drawMap() override;
        void handleCamera() override;
        void draw3D() override;
        void draw2D() override;
        void beforeDrawing() override;
        void beforeMode() override;

    private:
        int _focusRect;
        std::string _port;
        std::string _id;
};

#endif /* !MENU_HPP_ */
