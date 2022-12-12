/*
** EPITECH PROJECT, 2019
** my_hunter.c
** File description:
** main function .c
*/

#include "include/my.h"

void destroys_sprites(display_s *toto, files_s *files)
{
    sfMusic_destroy(toto->music1);
    sfMusic_destroy(toto->music2);
    sfSprite_destroy(toto->death);
    sfSprite_destroy(toto->respawn);
    sfSprite_destroy(toto->fish);
    sfSprite_destroy(toto->crosshair);
    sfSprite_destroy(toto->heart1);
    sfSprite_destroy(toto->heart2);
    sfSprite_destroy(toto->heart3);
    sfSprite_destroy(toto->score_bg);
    sfText_destroy(toto->text);
    sfText_destroy(toto->score_text);
    sfSprite_destroy(toto->bg);
}

int start(int ac, char **av)
{   
    sfEvent event;
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    display_s *toto = malloc(sizeof(display_s));
    files_s *files = malloc(sizeof(files_s));
    window = sfRenderWindow_create(mode, "MINECRAFT FISH CLICKER", sfResize | sfClose, NULL);
    launch(window, event, toto, files);
    destroys_sprites(toto, files);
    sfRenderWindow_destroy(window);
    return 0;
}

int main(int ac, char **av)
{   
    const char *help = "\n\n                -= MINECRAFT"
    " FISH CLICKER =-\n\n"
    "            Minecraft fish clicker is a fish 360\n"
    "            noscope hunting game that consists in\n"
    "            hunting fish by clicking on them.\n\n\n";
    const char *usage = "\n\nGUIDE: \"./my_hunter -h\" for an introduction"
    "to the game or \"./my_hunter\" to execute.\n\n\n";

    if (ac == 2 && (av[1][0] == 'h' || av[1][1] == 'h')) {
        my_putstr(help);
        return 0;
    }
    printf("test\n");
    //if (ac > 2 || (av[1][0] != 'h' || av[1][1] != 'h')) {
    //    my_putstr(usage);
    //    return 0;
    //}
    start(ac, av);
    return 0;
}