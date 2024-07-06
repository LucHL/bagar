/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_
    #include "../AScene.hpp"

class Menu : public AScene {
    public:
        Menu();
        ~Menu();

        void drawPlayer() override;
        void drawMap() override;
        void handleCamera() override;
        void draw2D() override;

    private:
};

#endif /* !MENU_HPP_ */
