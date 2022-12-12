/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeees
*/

#include "my.h"

int prompt_loop(st_s *st, char **env)
{
    while (1) {
        if (get_line(st) == 84)
            return (0);
        st->l_table = get_wordtab_inp(st->input);
        if (st->l_table[0] == NULL)
            continue;
        for (st->noa = 0; st->l_table[st->noa]; st->noa++);
        check_builtin(st);
        if (st->builtin == 0) {
            st->pid = fork();
            if (st->pid == -1)
                break;
            execute_sysfunction(st);
        }
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    st_s *st = malloc(sizeof(st_s));
    char s[500];

    if (env == NULL)
        return (0);
    st->pid = 0;
    st->status = 0;
    st->home_line = 0;
    st->home_update = 0;
    st->home_path = NULL;
    st->env = my_dup_array(env, 0);
    st->path = get_wordtab_env(env);
    st->current = getcwd(s, 500);
    set_home(st);
    if (prompt_loop(st, env) == 0)
        return (0);
    return (0);
}