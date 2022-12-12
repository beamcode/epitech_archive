/*
** EPITECH PROJECT, 2020
** c
** File description:
** c
*/

#include "include/my.h"
#include <math.h>

void clear_framebuffer(t_framebuffer *bf, t_window *utils)
{
    int s = (1080 * 1920 * 4);
    sfTime timer = sfClock_getElapsedTime(utils->clock);
    float seconds = timer.microseconds / 1000000.0;

    if (seconds > 0.000000001) {
        memset(bf -> pixels, 5, s);
        sfClock_restart(utils->clock);
    }
}

int close_window(t_framebuffer *framebuffer, t_window *utils)
{
    free(framebuffer);
    sfSprite_destroy(utils->sprite);
    sfTexture_destroy(utils->texture);
    sfRenderWindow_destroy(utils->window);
    return (0);
}

t_framebuffer *framebuffer_create(unsigned int width, unsigned int height)
{
    int s = (width * height * 4);
    t_framebuffer *fr = malloc(sizeof(t_framebuffer));
    fr->width = width;
    fr->height = height;
    fr->pixels = malloc(sizeof(sfUint8) * width * height * 4);
    memset(fr -> pixels, 0, s);
    return (fr);
}

int my_put_pixel(t_framebuffer *fr, unsigned int x, unsigned y, sfColor color)
{
    if (x > fr->width || y > fr->height)
        return (84);
    fr->pixels[(x + y * fr -> width) * 4 + 0] = color.r;
    fr->pixels[(x + y * fr -> width) * 4 + 1] = color.g;
    fr->pixels[(x + y * fr -> width) * 4 + 2] = color.b;
    fr->pixels[(x + y * fr -> width) * 4 + 3] = color.a;
    return (0);
}

int draw_moving_balance(t_framebuffer *bf, sfVector2i center, int radius)
{
    sfColor color;
    color.r = 255;
    color.g = 0;
    color.b = 0;
    color.a = 200;

    for (int i = center.y - radius; i <= center.y + radius; i++) {
        for (int j = center.x - radius; j <= center.x + radius; j++) {
            if (pow(j - center.x, 2) + pow(i - center.y, 2) <= pow(radius, 2)) {
                my_put_pixel(bf, j, i, color);
            }
        }
    }
    return (0);
}
