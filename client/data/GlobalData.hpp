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

class GlobalData {
    public:
        ~GlobalData();

        static GlobalData &getInstance();
        Camera3D &getCam3D();
        Camera2D &getCam2D();
        bool &boolGameClose();
        std::unordered_map<int, std::string> &getKey();
    
    protected:
        GlobalData();

    private:
        Camera3D _cam3;
        Camera2D _cam2;
        bool _closeGame;
        std::unordered_map<int, std::string> _key;
};

#endif /* !GLOBALDATA_HPP_ */
