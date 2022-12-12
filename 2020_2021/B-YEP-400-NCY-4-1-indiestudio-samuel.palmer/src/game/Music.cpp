/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** music
*/

#include "Music.hpp"

_Music::_Music(const std::string &path)
{
    music = LoadMusicStream(strToChar(path));
}

_Music::~_Music()
{
}

void _Music::play_music()
{
    PlayMusicStream(music);
}

void _Music::update_music()
{
    UpdateMusicStream(music);
}

void _Music::set_volume(float vol)
{
    SetMusicVolume(music, vol);
}
