/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

int convert_input(char inp, int a)
{
    int x = 2;

    if (a == 0) {
        for (int a = 65; a < inp; a++)
            x += 2;
    }
    else {
        for (int a = 49; a < inp; a++)
            x++;
    }
    return (x);
}

void check_success(st_s *st, char *line)
{
    int y = convert_input(line[1], 1);
    int x = convert_input(line[0], 0);

    pause();
    my_putchar(line[0]);
    my_putchar(line[1]);
    if (vg.global == SIGUSR1) {
        st->enemy_map[y][x] = 'o';
        my_putstr(": missed\n\n");
    }
    if (vg.global == SIGUSR2) {
        st->enemy_map[y][x] = 'x';
        my_putstr(": hit\n\n");
    }
}

void attack_ship(st_s *st)
{
    my_putchar(st->map[0][st->x]);
    my_putchar(st->map[st->y][0]);
    if (st->map[st->y][st->x] == '.' || st->map[st->y][st->x] == 'o' ||
        st->map[st->y][st->x] == 'x') {
        st->map[st->y][st->x] = 'o';
        usleep(10000);
        kill(vg.pid, SIGUSR1);
        my_putstr(": missed\n\n");
    }
    else {
        st->map[st->y][st->x] = 'x';
        usleep(10000);
        kill(vg.pid, SIGUSR2);
        my_putstr(": hit\n\n");
    }
}

void send_signal(char *inp)
{
    for (int a = 49; a < inp[1]; a++) {
        usleep(10000);
        kill(vg.pid, SIGUSR1);
    }
    usleep(10000);
    kill(vg.pid, SIGUSR2);
    for (int a = 65; a < inp[0]; a++) {
        usleep(10000);
        kill(vg.pid, SIGUSR1);
    }
    usleep(10000);
    kill(vg.pid, SIGUSR2);
}

void receive_signal(st_s *st)
{
    st->y = 2;
    st->x = 2;

    while (1) {
        pause();
        if (vg.global == SIGUSR1)
            st->y++;
        if (vg.global == SIGUSR2)
            break;
    }
    while (1) {
        pause();
        if (vg.global == SIGUSR1)
            st->x += 2;
        if (vg.global == SIGUSR2)
            break;
    }
}
