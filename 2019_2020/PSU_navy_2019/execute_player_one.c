/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

static void game_loop(st_s *st)
{
    char *line = NULL;

    print_maps(st);
    while (1) {
        line = get_input(st);
        send_signal(line);
        check_success(st, line);
        if (verify_win(st) == 1)
            return;
        my_putstr("waiting for enemy's attack...\n");
        receive_signal(st);
        attack_ship(st);
        if (verify_win(st) == 1)
            return;
        print_maps(st);
    }
}

void execute_player_one(st_s *st)
{
    st->my_pid = getpid();
    struct sigaction sig;

    sigemptyset(&sig.sa_mask);
    sig.sa_sigaction = sig_handler;
    sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    my_putstr("my_pid: ");
    my_putnbr(st->my_pid);
    my_putstr("\nwaiting for ennemy's connexion...\n");
    while (vg.global != SIGUSR1)
        pause();
    kill(vg.pid, SIGUSR1);
    my_putstr("\nenemy connected\n\n");
    game_loop(st);
}
