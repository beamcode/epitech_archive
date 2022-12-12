/*
** EPITECH PROJECT, 2020
** get music
** File description:
** get music
*/
#include "include/my.h"

music_t *set_volume(music_t *music)
{
    sfMusic_setVolume(music->menumusic, music->menu_v);
    sfMusic_setVolume(music->gamemusic, music->menu_v);
    sfMusic_setVolume(music->radio, music->sound_v);
    sfMusic_setVolume(music->radio2, music->sound_v);
    sfMusic_setVolume(music->radio3, music->sound_v);
    sfMusic_setVolume(music->quest, music->game_v);
    sfMusic_setVolume(music->grow, music->sound_v);
    sfMusic_setVolume(music->typing, music->sound_v);
    sfMusic_setVolume(music->cine, music->menu_v);
    sfMusic_setVolume(music->credits, music->game_v);
    return (music);
}
    
music_t *get_music(void)
{
    music_t *music = malloc(sizeof(music_t));

    if (music != NULL) {
        music->menumusic = sfMusic_createFromFile("ressources/menumusic.ogg");
        music->gamemusic = sfMusic_createFromFile("ressources/gamemusic.ogg");
        music->radio = sfMusic_createFromFile("ressources/radio.ogg");
        music->radio2 = sfMusic_createFromFile("ressources/radio2.ogg");
        music->radio3 = sfMusic_createFromFile("ressources/radio3.ogg");
        music->quest = sfMusic_createFromFile("ressources/quest.ogg");
        music->grow = sfMusic_createFromFile("ressources/grow.ogg");
        music->typing = sfMusic_createFromFile("ressources/typing.ogg");
        music->cine = sfMusic_createFromFile("ressources/cine.ogg");
        music->credits = sfMusic_createFromFile("ressources/credits.ogg");
        music->menu_v = 20;
        music->game_v = 20;
        music->sound_v = 30;
        music = set_volume(music);
    }
    return (music);
}
