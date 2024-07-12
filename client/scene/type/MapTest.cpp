/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** MapTest
*/

#include "MapTest.hpp"

MapTest::MapTest()
{
}

MapTest::~MapTest()
{
}

void MapTest::drawPlayer()
{

}

void MapTest::drawMap()
{

}

void MapTest::handleCamera()
{

}

void MapTest::draw3D()
{
    blockCursor();
    DrawGrid(20, 1.0f);
    DrawCube({0.0f, 0.0f, 0.0f}, 2.0f, 2.0f, 2.0f, GREEN);
    DrawCubeWires({0.0f, 0.0f, 0.0f}, 2.0f, 2.0f, 2.0f, MAROON);
}

void MapTest::draw2D()
{
    DrawFPS(10, 10);
}

void MapTest::beforeDrawing()
{
    GlobalData &data = GlobalData::getInstance();
    UpdateCamera(&data.getCam3D(), CAMERA_FIRST_PERSON);

    if (IsKeyPressed(KEY_ESCAPE)) {
        SceneManager &scene = SceneManager::getInstance();
        data.getCurrentScene() = scene.changeScene(MENU);
    }

    if (IsKeyPressed(KEY_P)) {              //! - DEBUG - Touche P sorti du programme
        data.boolGameClose() = true;
    }
}

void MapTest::beforeMode()
{
    ClearBackground(RAYWHITE);
}

void MapTest::blockCursor()
{
    SetMousePosition(GetScreenWidth() / 2, GetScreenHeight() / 2);
}
