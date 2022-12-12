/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeees
*/

#include "my.h"

void print_error(st_s *st)
{
    const char *error = ": Command not found.\n";

    my_putstr(st->l_table[0]);
    my_putstr(error);
}

int find_command(st_s *st)
{
    char *temp;

    for (int x = 0; st->path[x]; x++) {
        temp = my_strconcat(st->path[x], st->l_table[0]);
        if (access(temp, F_OK) == 0) {
            st->ac_path = temp;
            return (1);
        }
    }
    return (0);
}

int execute_binary(pid_t kid, st_s *st)
{
    if (check_binary(st) == 1) {
        execve(st->binary_path, st->l_table, st->env);
        return (1);
    }
    return (0);
}

void execute_system(pid_t kid, st_s *st)
{
    if (find_command(st) == 1)
        execve(st->ac_path, st->l_table, st->env);
    else {
        print_error(st);
        kill(kid, 9);
    }
}

void execute_sysfunction(st_s *st)
{
    pid_t kid = getpid();
    int d = 0;

    if (st->pid == 0) {
        if (execute_binary(kid, st) == 1)
            d = 1;
        else
            execute_system(kid, st);
    }
    else {
        waitpid(st->pid, &st->status, 0);
        if (WIFSIGNALED(st->status) == 1) {
            if (st->status == 2)
                my_putstr("\n$>");
            if (st->status == 11)
                my_puterr("Segmentation fault\n");
            if (st->status == 8)
                my_puterr("Floating exception\n");
        }
    }
}