/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** window
*/

#include "Window.hpp"

_Window::_Window(int _screenWidth, int _screenHeight, const std::string &title)
{
    screenWidth = _screenWidth;
    screenHeight = _screenHeight;
    SetTraceLogLevel(LOG_ERROR);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, title.c_str());
    SetTargetFPS(60);
    InitAudioDevice();
}

_Window::~_Window()
{
    CloseWindow();
}
