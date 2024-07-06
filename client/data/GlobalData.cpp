/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** GlobalData
*/

#include "GlobalData.hpp"

GlobalData::GlobalData()
{
    _cam3 = {0};
    _cam2 = {0};
    _closeGame = false;
}

GlobalData::~GlobalData()
{
}

GlobalData &GlobalData::getInstance()
{
    static GlobalData data;
    return data;
}

Camera3D &GlobalData::getCam3D()
{
    return _cam3;
}

Camera2D &GlobalData::getCam2D()
{
    return _cam2;
}

bool &GlobalData::boolGameClose()
{
    return _closeGame;
}
