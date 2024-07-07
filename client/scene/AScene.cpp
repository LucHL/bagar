/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** AScene
*/

#include "AScene.hpp"

AScene::AScene()
{
}

AScene::~AScene()
{
}

void AScene::drawPlayer()
{

}

void AScene::drawMap()
{

}

void AScene::handleCamera()
{

}

void AScene::draw3D()
{

}

void AScene::draw2D()
{

}

std::string AScene::handleKeyBoard()
{
    GlobalData &data = GlobalData::getInstance();
    for (auto &i : data.getKey()) {
        if (IsKeyPressed(i.first)) {
            return i.second;
        }
    }
    return "";
}

void AScene::beforeDrawing()
{

}

void AScene::beforeMode()
{

}
