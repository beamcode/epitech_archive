/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Sound
*/

#ifndef Sound_HPP_
#define Sound_HPP_

#include <raylib.h>
#include <string>

class _Sound {
    public:
        _Sound(const std::string &path);
        ~_Sound();

        template<typename T>
        const char *strToChar(const T &str) {
            return (str.c_str());
        }
        void play_sound();
        void set_volume(float vol);
        void stop_sound();
        void stopAllSound();
        void changeSound(const std::string &path);

    protected:
    private:
        Sound sound;
};

#endif /* !Sound_HPP_ */
