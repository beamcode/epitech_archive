/*
** EPITECH PROJECT, 2019
** create win
** File description:
** create win
*/
#include "include/my.h"

sfRenderWindow *create_my_window(int a, int b)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = a;
    video_mode.height = b;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "RPG", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}
