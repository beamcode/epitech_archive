/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

int check_pal(int num)
{
    int revN = 0;
    int originalN = num;

    for (int rem = 0; num != 0;) {
        rem = num % 10;
        revN = revN * 10 + rem;
        num /= 10;
    }
    if (originalN == revN)
        return (1);
    return (0);
}

int iterate_num(int num, int base)
{
    int temp = num;
    int rev = 0;
    int a = 0;
    
    while (num != 0) {
        rev = rev * 10;
        rev = rev + num % 10;
        num = num / 10;
    }
    a = convert_to_dec(temp, base) + convert_to_dec(rev, base);
    return (convert_to_base(a, base));
}

int check_print(st_s *st, int count, int iter, int temp)
{
    if (temp == convert_to_base(st->num, st->base) && \
        (iter >= st->imin && iter <= st->imax)) {
        printf("%d leads to %d in %d iteration(s) in base %d\n"\
        , count, st->num, iter, st->base);
        return (1);
    }
    return (0);
}

void do_base_algo(st_s *st)
{
    int num = convert_to_base(st->num, st->base);
    int count = 1;
    int total = 0;

    for (int iter = 0, temp = 1; 1; iter = 0) {
        for (; temp <= num; iter++) {
            if (temp == num)
                break;
            temp = iterate_num(temp, st->base);
        }
        total += check_print(st, count, iter, temp);
        count++;
        temp = convert_to_base(count, st->base);
        if (count > num || temp <= 0)
            break;
    }
    if (total == 0)
        printf("no solution\n");
}

void do_algo(st_s *st)
{
    int temp = convert_to_base(st->num, st->base);
    int iter = 0;

    if (st->option == 45) {
        for (; iter != st->imax + 1;) {
            if ((check_pal(temp) == 1 && convert_to_dec(temp, st->base) != -1\
                && (iter >= st->imin && iter <= st->imax)) || (temp <= 0))
                break;
            iter++;
            temp = iterate_num(temp, st->base);
        }
        if (check_pal(temp) == 1 && (iter >= st->imin && iter <= st->imax) \
            && convert_to_dec(temp, st->base) != 0)
            printf("%d leads to %d in %d iteration(s) in base %d\n"\
            , st->num, convert_to_dec(temp, st->base), iter, st->base);
        else
            printf("no solution\n");
    }
    if (st->option == 44)
        do_base_algo(st);
}