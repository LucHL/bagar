/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
    #define AUDIO_HPP_
    #include "raylib.h"
    #include <iostream>

class Audio {
    public:
        Audio();
        Audio(std::string path, bool startMusic);
        ~Audio();

        void startMusic();
        void PauseMusic();
        void StopMusic();
        void changeMusic(std::string path, bool startMusic);
        void updateMusic();

    private:
        std::string _path;
        Music _music;
};

#endif /* !AUDIO_HPP_ */
