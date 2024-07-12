/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** Menu
*/

#include "Menu.hpp"
#include "../SceneManager.hpp"

Menu::Menu()
{
    _focusRect = 0;
    _music = Audio("client/assets/music/menu/Brawlhalla_menu.mp3", true);
}

Menu::~Menu()
{
}

void Menu::drawPlayer()
{

}

void Menu::drawMap()
{

}

void Menu::handleCamera()
{

}

void Menu::draw3D()
{
}

void Menu::draw2D()
{
    DrawText("BAGAR", GetScreenWidth() / 2.3, 100, 70, RAYWHITE);
    Rectangle id = { (float)(GetScreenWidth() / 2.7), (float)(GetScreenHeight() / 3.5), 500, 50 };
    Rectangle port = { (float)(GetScreenWidth() / 2.7), (float)(GetScreenHeight() / 2.5), 500, 50 };
    Rectangle start = { (float)(GetScreenWidth() / 2.23), (float)(GetScreenHeight() / 1.5), 200, 50 };

    std::string character = handleKeyBoard();
    if (CheckCollisionPointRec(GetMousePosition(), port)) {
        _focusRect = 1;
        if (character == "BACKSPACE" && !_port.empty())
            _port.pop_back();
        else if (character != "BACKSPACE")
            _port += character;
    } else if (CheckCollisionPointRec(GetMousePosition(), id)) {
        _focusRect = 2;
        if (character == "BACKSPACE" && !_id.empty())
            _id.pop_back();
        else if (character != "BACKSPACE")
            _id += character;
    }

    DrawText("ID", GetScreenWidth() / 3.3, GetScreenHeight() / 3.5, 50, RAYWHITE);
    DrawRectangleRec(id, RAYWHITE);
    DrawText(_id.c_str(), GetScreenWidth() / 2.5, GetScreenHeight() / 3.4, 35, BLACK);

    DrawText("PORT", GetScreenWidth() / 3.5, GetScreenHeight() / 2.5, 50, RAYWHITE);
    DrawRectangleRec(port, RAYWHITE);
    DrawText(_port.c_str(), GetScreenWidth() / 2.5, GetScreenHeight() / 2.45, 35, BLACK);

    DrawRectangleRec(start, RAYWHITE);
    DrawText("START", GetScreenWidth() / 2.15, GetScreenHeight() / 1.49, 40, BLACK);

    // TODO add button for user name

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), start)) {
        GlobalData &data = GlobalData::getInstance();
        SceneManager &scene = SceneManager::getInstance();
        data.getCurrentScene() = scene.changeScene(MAPTEST);
    }
}

void Menu::beforeDrawing()
{
    _music.updateMusic();

    if (IsKeyPressed(KEY_ESCAPE)) {
        GlobalData &data = GlobalData::getInstance();
        data.boolGameClose() = true;
    }
}

void Menu::beforeMode()
{
    ClearBackground(BLACK);
}
