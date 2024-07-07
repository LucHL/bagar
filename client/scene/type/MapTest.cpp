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
    DrawGrid(10, 1);
    DrawCube({0,0,0}, 50, 50, 50, GREEN);
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
}

void MapTest::beforeMode()
{
    ClearBackground(RAYWHITE);
}

void MapTest::blockCursor()
{
    SetMousePosition(GetScreenWidth() / 2, GetScreenHeight() / 2);
}
