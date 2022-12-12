/*
** EPITECH PROJECT, 2019
** clock_func.c
** File description:
** yes
*/

#include "include/my.h"

//sfVector2f (*follow_path)(sfSprite *s, int speed);

sfVector2f follow_path(sfSprite *sprite, float speed)
{
    sfVector2f goblin = sfSprite_getPosition(sprite);

    if (goblin.x < 135)
        return (pos(2 * speed, -0.25 * speed));
    if (goblin.x < 197)
        return (pos(0.6 * speed, -2 * speed));
    if (goblin.x < 380)
        return (pos(2 * speed, 0));
    if (goblin.x < 437)
        return (pos(0.3 * speed, 2 * speed));
    if (goblin.x < 695)
        return (pos(2 * speed, 0));
    if (goblin.x < 742)
        return (pos(0.45 * speed, -2 * speed));
    if (goblin.x < 1375)
        return (pos(2 * speed, 0));
    else
        pos_sprite(sprite, pos(-95, 350));
    return ((sfVector2f) {0, 0});
}

void draw_enemies(st_s *st)
{
    st->goblin_time = sfClock_getElapsedTime(st->goblin_clock);
    if (st->goblin_time.microseconds / 1000000.0 > 0.10) {
        if (st->goblin_rect.left < 475)
            st->goblin_rect.left += 95;
        else 
            st->goblin_rect.left = 0;
        sfClock_restart(st->goblin_clock);
    }
    sfSprite_setTextureRect(st->goblin_sprite, st->goblin_rect);
    draw_sprite(st->window, st->goblin_sprite, NULL);
}

void game_window(st_s *st)
{
    //positions
    sfSprite_move(st->goblin_sprite, follow_path(st->goblin_sprite, 0.5));
    pos_sprite(st->cursor_sprite, pos_mouse(st, st->window));

    //draws
    draw_sprite(st->window, st->map_sprite, NULL);
    draw_enemies(st);
    draw_towers(st);
    //score
    if (st->score < 1000)
        st->score++;
    sfText_setString(st->score_text, my_strconcat("Score: ", my_itoa(st->score)));
    sfRenderWindow_drawText(st->window, st->score_text, NULL);
    //flech
    draw_sprite(st->window, st->cursor_sprite, NULL);
}

void start_game(st_s *st, int ac, char **av)
{   
    //sfMusic_play(st->game_music);
    while (sfRenderWindow_isOpen(st->window)) {
        while (sfRenderWindow_pollEvent(st->window, &st->event))
            check_events(st);
        st->pos_cursor = sfMouse_getPositionRenderWindow(st->window);
        pos_sprite(st->cursor_sprite, pos_mouse(st, st->window));

        st->game_time = sfClock_getElapsedTime(st->game_clock);
        if (st->game_time.microseconds / 1000000.0 > 1.0 / 60.0) {
            sfRenderWindow_clear(st->window, sfWhite);
            game_window(st);
            sfRenderWindow_display(st->window);
            sfClock_restart(st->game_clock);
        }
    }
    sfMusic_stop(st->game_music);
}

void init_struct(st_s *st)
{
    st->game_clock = sfClock_create();
    //map
    st->map_sprite = sfSprite_create();
    st->map_texture = sfTexture_createFromFile
    ("map1.png", NULL);
    sfSprite_setTexture(st->map_sprite, st->map_texture, sfTrue);

    //cursor
    st->cursor_sprite = sfSprite_create();
    st->cursor_texture = sfTexture_createFromFile
    ("cursor.png", NULL);
    sfSprite_setTexture(st->cursor_sprite, st->cursor_texture, sfTrue);

    //preview
    st->preview_sprite = sfSprite_create();
    st->preview_texture = sfTexture_createFromFile
    ("preview.png", NULL);
    sfSprite_setTexture(st->preview_sprite, st->preview_texture, sfTrue);

    //goblin
    st->goblin_sprite = sfSprite_create();
    st->goblin_texture = sfTexture_createFromFile
    ("goblin.png", NULL);
    sfSprite_setTexture(st->goblin_sprite, st->goblin_texture, sfTrue);
    st->goblin_clock = sfClock_create();
    st->goblin_rect.width = 95;
    st->goblin_rect.height = 95;
    st->goblin_rect.left = 0;
    st->goblin_rect.top = 95;
    pos_sprite(st->goblin_sprite, pos(-95, 350));

    //creation de tout se quil faux pour les tour ici
    st->slots = malloc(sizeof(int) * 7);
    for (int x = 0; x < 8; x++)
        st->slots[x] = 3;
    st->tower_texture = malloc(sizeof(sfTexture *) * 3);
    st->towers = malloc(sizeof(sfSprite **) * 7);
    st->t_clock = malloc(sizeof(sfClock *) * 7);
    st->t_time = malloc(sizeof(sfTime) * 7);
    st->t_rect = malloc(sizeof(sfIntRect) * 7);
    st->tower_texture[0] = sfTexture_createFromFile("tower1.png", NULL);
    st->tower_texture[1] = sfTexture_createFromFile("tower2.png", NULL);
    st->tower_texture[2] = sfTexture_createFromFile("tower3.png", NULL);
    for (int a = 0; a < 7; a++) {
        st->t_rect[a].width = 300;
        st->t_rect[a].height = 300;
        st->t_rect[a].left = 0;
        st->t_rect[a].top = 0;
        st->t_clock[a] = sfClock_create();
        st->towers[a] = malloc(sizeof(sfSprite *) * 3);
        for (int x = 0; x < 3; x++) {
            st->towers[a][x] = sfSprite_create();
            sfSprite_setTexture(st->towers[a][x], st->tower_texture[x], sfTrue);
        }
    }
    for (int a = 0; a < 3; a++) {
        pos_sprite(st->towers[0][a], pos(176, 100));
        pos_sprite(st->towers[1][a], pos(175, 215));
        pos_sprite(st->towers[2][a], pos(400, -35));
        pos_sprite(st->towers[3][a], pos(460, 255));
        pos_sprite(st->towers[4][a], pos(450, 495));
        pos_sprite(st->towers[5][a], pos(720, 50));
        pos_sprite(st->towers[6][a], pos(750, 290));
    }

    //st->score_font = sfFont_createFromFile("font.ttf");
    st->score = 0;
    st->score_text = sfText_create();
    sfText_setFont(st->score_text, sfFont_createFromFile("font.ttf"));
         //changer couleur text --> sfText_setColor(st->score_text, sfBlack);
    sfText_setPosition(st->score_text, (sfVector2f) {900.0, 1.5});
    sfText_setScale(st->score_text, (sfVector2f) {1.5, 1.5});

    //music
    st->game_music = sfMusic_createFromFile("track1.ogg");
    st->click_music = sfMusic_createFromFile("click.ogg");
    sfMusic_setLoop(st->game_music, sfTrue);

}

//(st->towers)[3] = NULL;
/*
int sprite_creator(sfSprite ***sprite, sfTexture ***text, sfFloatRect **rect)
{
    *sprite = malloc(sizeof(sfSprite *) * (size + 1));
    *text = malloc(sizeof(sfTexture *) * (size + 1));
    *rect = malloc(sizeof(sfFloatRect) * size);

    for (int i = 0; i < 3; i++) {
        sfSprite_setTexture((*sprite)[i], (*text)[i], sfTrue);
        sfSprite_setPosition((*sprite)[i], (sfVector2f){converter(), converter()});
        sfSprite_setScale((*sprite)[i], (sfVector2f){converter(), converter()});
    }
    (*sprite)[size] = NULL;
    (*text)[size] = NULL;
    return (0);
}
*/

int create_window(int ac, char **av)
{
    st_s *st = malloc(sizeof(st_s));
    sfVideoMode mode = {1280, 720, 32};
    const char *name = "-= Tower Defence =-";
    st->window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(st->window, 60);
    sfRenderWindow_setMouseCursorVisible(st->window, sfFalse);

    init_struct(st);
    start_game(st, ac, av);
    return (0);
}