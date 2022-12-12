/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <raylib.h>
#include <string>

class _Window {
    public:
        _Window(int _screenWidth, int _screenHeight, const std::string &title);
        ~_Window();

    protected:
    private:
        int screenWidth;
        int screenHeight;
};

#endif /* !WINDOW_HPP_ */
