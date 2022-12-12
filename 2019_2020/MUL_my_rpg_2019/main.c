/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/
#include "include/my.h"

void my_print_usage(void)
{
    my_putstr("The solution can be found in Solution.txt\n");
}

int main (int argc, char **argv)
{
    game_t *game;

    if (argc == 1) {
        game = fill_my_game();
        get_map("scripts/game", game);
        return (open_window(game));
    }
    else if (my_strcmp(argv[1], "-h") == 1) {
        my_print_usage();
        return (0);
    }
    else
        return (84);
}
