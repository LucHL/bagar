/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** Music
*/

#include "Music.hpp"

Music::Music(std::string path) : _path(path)
{
    _music = LoadSound(_path.c_str());
}

Music::~Music()
{
}

Sound &Music::getMusic()
{
    return _music;
}

void Music::newMusic(std::string next)
{

}

void Music::setPause(bool pause)
{

}
