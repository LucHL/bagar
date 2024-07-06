/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** GlobalData
*/

#ifndef GLOBALDATA_HPP_
    #define GLOBALDATA_HPP_
    #include "raylib.h"

class GlobalData {
    public:
        ~GlobalData();

        static GlobalData &getInstance();
        Camera3D &getCam3D();
        Camera2D &getCam2D();
        bool &boolGameClose();
    
    protected:
        GlobalData();

    private:
        Camera3D _cam3;
        Camera2D _cam2;
        bool _closeGame;
};

#endif /* !GLOBALDATA_HPP_ */
