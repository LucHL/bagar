/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

SceneManager::SceneManager() : _current(MENU)
{
}

SceneManager::~SceneManager()
{
}

SceneManager &SceneManager::getInstance()
{
    static SceneManager scene;
    return scene;
}

std::shared_ptr<IScene> SceneManager::changeScene(Scene next)
{
    switch (next) {
        case MENU:
            _current = MENU;
            return std::make_shared<Menu>();
        case GAME:
            _current = GAME;
        case PAUSE:
            _current = PAUSE;
        case PARAM:
            _current = PARAM;
    }
    _current = MENU;
    return std::make_shared<Menu>();
}

Scene SceneManager::getCurrent()
{
    return _current;
}
