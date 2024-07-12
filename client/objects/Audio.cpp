/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** Audio
*/

#include "Audio.hpp"

Audio::Audio()
{
}

// if startMusic == true then PlayMusicStream
Audio::Audio(std::string path, bool startMusic) : _path(path)
{
    _music = LoadMusicStream(_path.c_str());

    if (startMusic)
        PlayMusicStream(_music);
}

Audio::~Audio()
{
}

void Audio::startMusic()
{
    PlayMusicStream(_music);
}

void Audio::PauseMusic()
{
    PauseMusicStream(_music);
}

void Audio::StopMusic()
{
    StopMusicStream(_music);
}

// if startMusic == true then PlayMusicStream
void Audio::changeMusic(std::string path, bool startMusic)
{
    _path = path;
    _music = LoadMusicStream(_path.c_str());

    if (startMusic)
        PlayMusicStream(_music);
}

void Audio::updateMusic()
{
    UpdateMusicStream(_music);
}
