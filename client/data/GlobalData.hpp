/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** GlobalData
*/

#ifndef GLOBALDATA_HPP_
    #define GLOBALDATA_HPP_
    #include "raylib.h"
    #include "unordered_map"
    #include <string>
    #include <memory>
    #include "../scene/IScene.hpp"

    #define _SCREEN_WIDTH GetScreenWidth()
    #define _SCREEN_HEIGHT GetScreenHeight()
    #define _FPS 60
    #define _MUSIC_VOLUME 10
    #define _SOUND_VOLUME 10

class GlobalData {
    public:
        ~GlobalData();

        static GlobalData &getInstance();
        Camera3D &getCam3D();
        Camera2D &getCam2D();
        bool &boolGameClose();
        std::unordered_map<int, std::string> &getKey();
        std::shared_ptr<IScene> &getCurrentScene();
    
    protected:
        GlobalData();

    private:
        Camera3D _cam3;
        Camera2D _cam2;
        bool _closeGame;
        std::unordered_map<int, std::string> _key;
        std::shared_ptr<IScene> _currentScene;
        std::string _userName;
};

#endif /* !GLOBALDATA_HPP_ */
