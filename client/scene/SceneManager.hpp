/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
    #define SCENEMANAGER_HPP_
    #include <memory>
    #include "AScene.hpp"
    #include "type/Menu.hpp"

enum Scene {
    MENU,
    GAME,
    PAUSE,
    PARAM
};

class SceneManager {
    public:
        ~SceneManager();

        static SceneManager &getInstance();
        std::shared_ptr<IScene> changeScene(Scene next);
        Scene getCurrent();

    protected:
        SceneManager();

    private:
        Scene _current;
};

#endif /* !SCENEMANAGER_HPP_ */