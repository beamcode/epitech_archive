/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** yess
*/

#include "include/my.h"

int check_within(int x1, int y1, int x2, int y2, sfVector2i pos_cursor)
{
    if ((pos_cursor.x >= x1 && pos_cursor.x <= x2) && \
        (pos_cursor.y >= y1 && pos_cursor.y <= y2))
        return (1);
    return (0);
}

int check_mouse_plots(st_s *st)
{
    int a = 0;

    if (check_within(265, 210, 390, 330, st->pos_cursor))
        a = 1;
    if (check_within(265, 330, 390, 450, st->pos_cursor))
        a = 2;
    if (check_within(490, 80, 615, 200, st->pos_cursor))
        a = 3;
    if (check_within(550, 365, 675, 485, st->pos_cursor))
        a = 4;
    if (check_within(535, 605, 660, 725, st->pos_cursor))
        a = 5;
    if (check_within(810, 160, 935, 280, st->pos_cursor))
        a = 6;
    if (check_within(840, 405, 965, 525, st->pos_cursor))
        a = 7;
    return (a);
}

void check_preview_pos(st_s *st, int prev)
{
    switch (prev) {
        case 1: sfSprite_setPosition(st->preview_sprite, pos(260, 195));
            break;
        case 2: sfSprite_setPosition(st->preview_sprite, pos(260, 310));
            break;
        case 3: sfSprite_setPosition(st->preview_sprite, pos(485, 60));
            break;
        case 4: sfSprite_setPosition(st->preview_sprite, pos(545, 350));
            break;
        case 5: sfSprite_setPosition(st->preview_sprite, pos(533, 590));
            break;
        case 6: sfSprite_setPosition(st->preview_sprite, pos(805, 140));
            break;
        case 7: sfSprite_setPosition(st->preview_sprite, pos(835, 390));
            break;
        default: return;
    }
}

int check_click(int x1, int y1, int sl, sfVector2i p)
{
    int sq = 70;
    int x = 0;

    if ((p.x >= x1 && p.x <= (x1 + sq)) && \
        (p.y >= y1 && p.y <= (y1 + sq)))
        x = 0;
    if ((p.x >= (x1 + sq) && p.x <= (x1 + (sq * 2))) && \
        (p.y >= y1 && p.y <= (y1 + sq)))
        x = 1;
    if ((p.x >= x1 && p.x <= (x1 + sq) && \
        (p.y >= (y1 + sq) && p.y <= (y1 + (sq * 2)))))
        x = 2;
    if ((p.x >= (x1 + sq) && p.x <= (x1 + (sq * 2)) && \
        (p.y >= (y1 + sq) && p.y <= (y1 + (sq * 2)))))
        x = 3;
    if ((x >= 0 && x <= 2) && (sl >= 0 && sl <= 2) )
        return (sl);
    return (x);
}


void switch_tower(st_s *st, int prev)
{
    if (prev == 1)
        st->slots[0] = check_click(265, 210, st->slots[0], st->pos_cursor);
    if (prev == 2)
        st->slots[1] = check_click(265, 330, st->slots[1], st->pos_cursor);
    if (prev == 3)
        st->slots[2] = check_click(490, 80, st->slots[2], st->pos_cursor);
    if (prev == 4)
        st->slots[3] = check_click(550, 365, st->slots[3], st->pos_cursor);
    if (prev == 5)
        st->slots[4] = check_click(535, 605, st->slots[4], st->pos_cursor);
    if (prev == 6)
        st->slots[5] = check_click(810, 160, st->slots[5], st->pos_cursor);
    if (prev == 7)
        st->slots[6] = check_click(840, 405, st->slots[6], st->pos_cursor);
}