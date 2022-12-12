/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <raylib.h>
#include <string>

class _Music {
    public:
        _Music(const std::string &path);
        ~_Music();

        template<typename T>
        const char *strToChar(const T &str) {
            return (str.c_str());
        }
        void update_music();
        void play_music();
        void set_volume(float vol);

    protected:
    private:
        Music music;
};

#endif /* !MUSIC_HPP_ */
