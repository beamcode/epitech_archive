/*
** EPITECH PROJECT, 2020
** cinematic
** File description:
** cinematic
*/
#include "include/my.h"

char *add_char(char *dest, int x)
{
    int a = 0;
    char *temp = malloc(sizeof(char) * x + 2);

    for (; a < x; a++)
        temp[a] = dest[a];
    a++;
    temp[a] = '\0';
    return (temp);
}

void increment_text(game_t *game)
{
    static int a = 0;
    static float tmp = 0;

    game->scroll_time = sfClock_getElapsedTime(game->scroll_clock);
    if (game->scroll_time.microseconds / 1000000.0 > 0.020) {
        if (game->story[a] != '\0') {
            game->temp = add_char(game->story, a);
            a++;
        }
        tmp += 0.1;
        sfClock_restart(game->scroll_clock);
        if (game->story[a] == '\0') {
            if (tmp > 180) {
                game->cinematic = 0;
                sfMusic_play(game->music->menumusic);
                sfMusic_setLoop(game->music->menumusic, sfTrue);
            }
            sfMusic_stop(game->music->typing);
        }
    }
}

char *get_my_map(char *av)
{
    int fd = open(av, O_RDONLY);
    struct stat buf;
    char *map;

    if (fd == -1)
        return (NULL);
    stat(av, &buf);
    map = malloc(sizeof(char) * (buf.st_size + 1));
    read(fd, map, buf.st_size);
    map[buf.st_size] = '\0';
    close(fd);
    return (map);
}

void draw_cinematic(game_t *game)
{
    static int tmp = 0;

    if (tmp == 0) {
        sfMusic_play(game->music->typing);
        sfMusic_setLoop(game->music->typing, sfTrue);
        sfMusic_setLoop(game->music->cine, sfTrue);
        tmp = 1;
    }
    increment_text(game);
    sfText_setString(game->text->scroll_text, game->temp);
}
