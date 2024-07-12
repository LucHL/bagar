/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** GlobalData
*/

#include "GlobalData.hpp"
#include "../scene/IScene.hpp"

GlobalData::GlobalData()
{
    _cam3 = {0};
    _cam2 = {0};
    _closeGame = false;
    _key = {
        {KEY_A, "A"}, {KEY_B, "B"}, {KEY_C, "C"}, {KEY_D, "D"},
        {KEY_E, "E"}, {KEY_F, "F"}, {KEY_G, "G"}, {KEY_H, "H"},
        {KEY_I, "I"}, {KEY_J, "J"}, {KEY_K, "K"}, {KEY_L, "L"},
        {KEY_M, "M"}, {KEY_N, "N"}, {KEY_O, "O"}, {KEY_P, "P"},
        {KEY_Q, "Q"}, {KEY_R, "R"}, {KEY_S, "S"}, {KEY_T, "T"},
        {KEY_U, "U"}, {KEY_V, "V"}, {KEY_W, "W"}, {KEY_X, "X"},
        {KEY_Y, "Y"}, {KEY_Z, "Z"},
        {KEY_SPACE, " "}, {KEY_ENTER, "ENTER"}, {KEY_ESCAPE, "ESCAPE"},
        {KEY_BACKSPACE, "BACKSPACE"}, {KEY_TAB, "TAB"},
        {KEY_ZERO, "0"}, {KEY_ONE, "1"}, {KEY_TWO, "2"}, {KEY_THREE, "3"},
        {KEY_FOUR, "4"}, {KEY_FIVE, "5"}, {KEY_SIX, "6"}, {KEY_SEVEN, "7"},
        {KEY_EIGHT, "8"}, {KEY_NINE, "9"}, {KEY_KP_0, "0"},
        {KEY_KP_1, "1"}, {KEY_KP_2, "2"}, {KEY_KP_3, "3"}, {KEY_KP_4, "4"},
        {KEY_KP_5, "5"}, {KEY_KP_6, "6"}, {KEY_KP_7, "7"}, {KEY_KP_8, "8"},
        {KEY_KP_9, "9"},
        {KEY_PERIOD, "."}, {KEY_KP_DECIMAL, "."}, {KEY_KP_SUBTRACT, "-"},
        {KEY_MINUS, "-"}
    };
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

std::unordered_map<int, std::string> &GlobalData::getKey()
{
    return _key;
}

std::shared_ptr<IScene> &GlobalData::getCurrentScene()
{
    return _currentScene;
}
