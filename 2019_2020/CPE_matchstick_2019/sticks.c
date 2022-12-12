/*
** EPITECH PROJECT, 2019
** sticks.c
** File description:
** yeee
*/

#include "includes/my.h"

void free_all(st_s *st)
{
    for (int a = 0; a <= (st->rows + 2); a++)
        free(st->map[a]);
}

int manage_errors(int ac, char **av)
{
    char *usage = "\nUSAGE: ./matchstick (size) (sticks per turn)\n\n";

    if (ac != 3) {
        my_putstr(usage);
        return (84);
    }
    for (int a = 0; av[1][a]; a++) {
        if (av[1][a] > 57 || av[1][a] < 48) {
            my_putstr(usage);
            return 84;
        }
    }
    for (int b = 0; av[2][b]; b++) {
        if (av[2][b] > 57 || av[2][b] < 48) {
            my_putstr(usage);
            return (84);
        }
    }
    return (0);
}

void change_turn(st_s *st)
{
    if (st->win == 0) {
        if (st->turn == 0)
            st->turn = 1;
        else
            st->turn = 0;
    }
}

int do_game_loop(st_s *st)
{
    while (st->win == 0) {
        if (st->turn == 0)
            my_putstr("Your turn:\n");
        if (st->turn == 0) {
            if (get_line(st) == -1)
                return (0);
            if (get_matches(st) == -1)
                return (0);
        }
        else
            play_computer(st);
        print_action_played(st);
        remove_matches(st);
        print_map(st);
        check_win(st);
        change_turn(st);
    }
    free_all(st);
    print_end_messages(st);
    return (st->win);
}

int main(int ac, char **av)
{
    st_s *st = malloc(sizeof(st_s));

    if (manage_errors(ac, av) == 84)
        return (84);
    st->rows = my_atoi(av[1]);
    st->max_matches = my_atoi(av[2]);
    init_values(st);
    create_map(st);
    if (do_game_loop(st) == 0)
        return (0);
    else
        return (st->win);
    return (0);
}