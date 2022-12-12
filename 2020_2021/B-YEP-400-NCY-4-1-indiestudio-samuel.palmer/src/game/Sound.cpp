/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Sound
*/

#include "Sound.hpp"

_Sound::_Sound(const std::string &path)
{
    sound = LoadSound(strToChar(path));
}

_Sound::~_Sound()
{
    //UnloadSound(sound);
}

void _Sound::play_sound()
{
    PlaySound(sound);
}

void _Sound::stop_sound()
{
    StopSound(sound);
}

void _Sound::stopAllSound()
{
    StopSoundMulti();
}

void _Sound::set_volume(float vol)
{
    SetSoundVolume(sound, vol);
}

void _Sound::changeSound(const std::string &path)
{
    sound = LoadSound(strToChar(path));
    set_volume(0.2);
}
