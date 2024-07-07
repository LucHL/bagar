/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** Music
*/

#ifndef MUSIC_HPP_
    #define MUSIC_HPP_
    #include "raylib.h"
    #include <iostream>

class Music {
    public:
        Music(std::string path);
        ~Music();

        Sound &getMusic();
        void newMusic(std::string next);
        void setPause(bool pause);

    private:
        std::string _path;
        bool _pause;
        Sound _music;
};

#endif /* !MUSIC_HPP_ */
