/*
** EPITECH PROJECT, 2019
** task02
** File description:
** task02
*/

#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef struct s_framebuffer
{
    sfUint8 *pixels;
    unsigned int width;
    unsigned int height;
} t_framebuffer;

typedef struct but_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int mark;
    int color;
    struct but_s *next;
}but_t;

typedef struct lifebar_s {
    sfRectangleShape *rect_s;
    sfVector2f pos;
    sfVector2f size;
    sfIntRect rect;
    int id;
} lifebar_t;


typedef struct s_circle
{
    sfVector2i center;
} t_circle;

typedef struct s_windwow
{
    sfRenderWindow* window;
    sfTexture* texture;
    sfSprite* sprite;
    sfClock *clock;
    sfVector2f pos;
}t_window;

typedef struct sprite_background_s {
    sfTexture *texturemap;
    sfSprite *spritemap;
}background_t;

typedef struct enemy_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int             hp;
    int             dmg;
    int mark;
    struct enemy_s *next;
}enemy_t;

typedef struct hero_t {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect       rec;
    sfSprite        *form;
    sfVector2f      pos;
    sfVector2f      nw;
    int            alive;
    int            select;
    int            played;
    int            move;
    int            attack;
    int            sword;
    int             spell_id;
    int             target;
    int             hp;
    int             dmg;
    int             armor;
} hero_t;

typedef struct battle_t {
    sfVector2f      *pos;
    int            run;
    sfVector2f      mouse;
    int             id;
    int             **mapi;
    int             number_fight;
    sfRectangleShape *icone;
    sfRectangleShape *background;
    sfTexture       **texture;
    sfText          *text;
    sfRectangleShape **map;
    sfClock         *clock;
} battle_t;

typedef struct fight_t {
    sfVector2f      pos;
    int             number_enemy;
    int            enemy_turn;
    int             curent;
    enemy_t         **enemy;
} fight_t;

typedef struct command_t {
    sfVector2i position_clic;
    sfVector2i pos_mouse;
    sfVector2f pos_tbase1;
    sfVector2f pos_tbase2;
    sfVector2f pos_tbase3;
    sfVector2f pos_tbase4;
    int mark;
    int attack;
} command_t;

typedef struct g_s
{
    command_t *command;
    but_t *but;
    enemy_t *enemy;
    hero_t *hero;
    battle_t *battle;
    sfRenderWindow *window;
    sfEvent event;
    sfFont *font_c;
    sfText *text_c;
    sfTime time_c;
    sfClock *clock_c;
    lifebar_t *pv_bar;
    t_framebuffer *framebuffer;
    background_t back;
    int sizex;
    int sizey;
    int nb_c;
}g_t;

typedef struct button_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int mark;
    struct button_s *next;
}button_t;

typedef struct mob_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f pos_max;
    sfVector2f pos_min;
    sfVector2f ipos;
    sfIntRect rect;
    float mv;
    int on;
    int tmp;
    int count;
    int mark;
    int map;
    int type;
    struct mob_s *next;
}mob_t;

typedef struct pnj_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f pos_max;
    sfVector2f pos_min;
    sfIntRect rect;
    int mark;
    int map;
    struct pnj_s *next;
}pnj_t;

typedef struct info_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int mark;
    struct info_s *next;
}info_t;

typedef struct item_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f pos_max;
    sfVector2f pos_min;
    int mark;
    int get;
    int on;
    int type;
    int damage;
    int resistance;
    int life;
    int mv_item;
    int helmet;
    int amulet;
    int chest;
    int boots;
    int ring;
    int sword;
    int jewel;
    struct item_s *next;
}item_t;

typedef struct stat_s {
    int ring_life;
    int jewel_life;
    int sword_life;
    int chest_life;
    int amulet_life;
    int boots_life;
    int helmet_life;
    int ring_dam;
    int jewel_dam;
    int sword_dam;
    int chest_dam;
    int amulet_dam;
    int boots_dam;
    int helmet_dam;
    int ring_res;
    int jewel_res;
    int sword_res;
    int chest_res;
    int amulet_res;
    int boots_res;
    int helmet_res;
}stat_t;

typedef struct player_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    int life;
    int level;
    int lifemax;
    int lifebar;
    int xpbar;
    int xp;
    int xpmax;
    int damage;
    int resistance;
    int points;
    int s_life;
    int s_dam;
    int s_res;
}player_t;

typedef struct text_s
{
    sfFont *font;
    sfText *life;
    sfText *lifemax;
    sfText *xp;
    sfText *xpmax;
    sfText *div;
    sfText *div2;
    sfText *time;
    sfText *lifestat;
    sfText *xpstat;
    sfText *points;
    sfText *res;
    sfText *dam;
    sfText *open_inv;
    sfText *pause;
    sfText *stats;
    sfText *quest;
    sfText *level;
    sfText *menu_v;
    sfText *game_v;
    sfText *sound_v;
    sfText *scroll_text;
    sfText *credits_text;
    sfText *key1;
    sfText *key2;
    sfText *key3;
}text_t;

typedef struct music_s
{
    sfMusic *menumusic;
    sfMusic *gamemusic;
    sfMusic *radio;
    sfMusic *radio2;
    sfMusic *radio3;
    sfMusic *quest;
    sfMusic *grow;
    sfMusic *typing;
    sfMusic *cine;
    sfMusic *credits;
    int game_v;
    int menu_v;
    int sound_v;
}music_t;

typedef struct obs_s
{
    sfVector2f pos_max;
    sfVector2f pos_min;
    int map_nb;
    int mark;
    struct obs_s *next;
}obs_t;

typedef struct map_s
{
    obs_t *obs;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    int mark;
    int nb;
    struct map_s *next;
}map_t;

typedef struct quest_s
{
    int q2;
    int q3;
    int q4;
    int q5;
    int q6;
    int quest;
    int boss;
}quest_t;

typedef struct game_s
{
    button_t *button;
    mob_t *mob;
    pnj_t *pnj;
    item_t *item;
    player_t *player;
    stat_t *stat;
    text_t *text;
    info_t *info;
    music_t *music;
    quest_t *quest;
    map_t *map;
    sfRenderWindow *window;
    sfClock *clock;
    sfClock *scroll_clock;
    sfSprite *perso_sprite;
    sfTexture *perso_texture;
    sfIntRect perso_rect;
    sfClock *perso_clock;
    sfTime perso_time;
    char *story;
    char *story2;
    char *temp2;
    char *temp;
    int cinematic;
    sfTime time;
    sfTime scroll_time;
    float seconds;
    float min;
    float mv;
    int hours;
    int credits;
    char *gametime;
    sfEvent event;
    sfVector2i pos_mouse;
    sfVector2i pos_clic;
    sfVector2f pos_cursor;
    sfVector2f pos_move;
    sfVector2f curs;
    int current_map;
    int new_game;
    int cur;
    int cur2;
    int key1;
    int key2;
    int key3;
    int key4;
    int apply;
    int p1_on;
    int p2_on;
    int p3_on;
    int p4_on;
    int pass;
    int s1;
    int s2;
    int s3;
    int s4;
    int menu1;
    int menu2;
    int menu3;
    int menu4;
    int on_move;
    float axe_y;
    float axe_x;
    int nb;
    int settings;
    int menu;
    int menupause;
    int inventory;
    int status;
}game_t;

void my_putchar(char c);
int my_putstr(char const *str);
sfRenderWindow *create_my_window(int a, int b);
int my_strlen(char *str);
void display_sprite(game_t *game);
void search_event(game_t *game);
int open_window(game_t *game);
void create_window(game_t *game);
game_t *fill_my_game(void);
int get_map(char *file, game_t *game);
int my_strcmp(char const *str1, char const *str2);
char **my_str_to_word_tab(char *line, char c);
void my_puterr(char const *error);
int my_put_nbr(int nb);
int my_atoi(char *str);
char *cleaning_str_tab(char *str);
int add_ring(game_t *game);
int add_sword(game_t *game);
int add_jewel(game_t *game);
int add_boots(game_t *game);
int add_chest(game_t *game);
int add_amulet(game_t *game);
int add_helmet(game_t *game);
int check_item_pos(game_t *game);
void check_item_move(game_t *game);
void check_inv_event(game_t *game);
void my_game_clock(game_t *game);
char *my_itoa(int nbr);
int set_ring(game_t *game);
int set_sword(game_t *game);
int set_jewel(game_t *game);
int set_boots(game_t *game);
int set_chest(game_t *game);
int set_amulet(game_t *game);
int set_helmet(game_t *game);
void change_player_stats(item_t *t, game_t *game);
button_t *fill_my_button(void);
map_t *fill_game_map(void);
mob_t *fill_my_mob(void);
item_t *fill_my_item(void);
map_t *add_map(char **tab, map_t *map);
button_t *add_button(char **tab, button_t *button);
mob_t *add_mob(char **tab, mob_t *mob);
item_t *add_item(char **tab, item_t *item);
player_t *get_player(void);
stat_t *get_item_stat(void);
char *my_strcat(char *buf, char *tmp);
void check_map_number(game_t *game);
obs_t *fill_game_obstacles(void);
obs_t *add_obs(char **tab, obs_t *obs);
void check_bar_sprite(game_t *game);
void init_text(text_t *text);
void draw_text(game_t *game);
int load_file(game_t *game, int tmp);
void check_settings_event(game_t *game);
void save_game(game_t *game);
void apply_text_modif(game_t *game);
void set_text_pos(game_t *game);
void check_status_event(game_t *game);
void check_menu_event(game_t *game);
void change_key(game_t *game);
char *check_keyabc(char *key);
char *check_keydef(char *key);
char *check_keyghi(char *key);
char *check_keyjkl(char *key);
char *check_keymno(char *key);
char *check_keypqr(char *key);
char *check_keystu(char *key);
char *check_keyvwx(char *key);
char *check_keyyze(char *key);
void check_obstacles(game_t *game);
void get_time(game_t *game);
map_t *fill_game_map(void);
obs_t *fill_game_obstacles(void);
info_t *fill_game_info(void);
pnj_t *fill_my_pnj(void);
pnj_t *add_pnj(char **tab, pnj_t *pnj);
info_t *add_info(char **tab, info_t *info);
void create_text(text_t *text);
void display_lifebar(game_t *game);
void display_xpbar(game_t *game);
void display_inventory(game_t *game);
void display_statusmenu(game_t *game);
void display_settings(game_t *game);
void apply_save(char **tab, game_t *game);
char *save_val_first(game_t *game);
char *save_val_sec(game_t *game);
char *save_val_three(game_t *game);
char *save_val_four(game_t *game);
char *save_val_five(game_t *game);
char *save_val_six(game_t *game);
char *save_val_seven(game_t *game);
char *save_val_eight(game_t *game);
void display_menu(game_t *game);
void move_right(game_t *game, int tmp);
void move_left(game_t *game, int tmp);
void move_up(game_t *game, int tmp);
void move_down(game_t *game, int tmp);
void check_pause_event(game_t *game);
void get_move_axes(game_t *game);
void search_fight(game_t *game);
void move_player(game_t *game);
void check_map_nine(game_t *game);
void check_map_number(game_t *game);
void check_map_four_two(game_t *game);
void check_map_five(game_t *game);
char *get_my_map(char *av);
void move_type_four(mob_t *t);
void move_type_one(mob_t *t);
void move_type_three(mob_t *t);
void move_type_two(mob_t *t);
void move_type_five(mob_t *t);
void move_type_six(mob_t *t);
quest_t *fill_quest(void);
music_t *get_music(void);
void free_array(char **array);
void display_quest(game_t *game, int tmp);
int check_quest_number(game_t *game, int tmp);
void check_quest_map(game_t *game);
void draw_cinematic(game_t *game);
void display_quest_indicator(game_t *game);
void display_quest_cursor(game_t *game);
void load_quest(game_t *game);
void display_mob_pnj(game_t *game);
void check_map_four(game_t *game);
void search_quest_event(game_t *game);
void check_map_seven(game_t *game);
void rect_second(mob_t *t);
void rect_third(mob_t *t);
void rect_six(mob_t *t);
void rect_seven(mob_t *t);
background_t init_back(void);
command_t *fill_my_command(void);
but_t *fill_my_but(void);
battle_t *fill_my_battle(void);
hero_t *fill_my_hero(void);
enemy_t *fill_my_enemy(void);
g_t *fill_my_game_two(void);
void display_rect_shape(sfRenderWindow *w, lifebar_t *lifebar, int nb_buttons);
lifebar_t *setup_fight(g_t *g);
int get_my_attack(g_t *game, command_t *c);
void get_my_type_attack(g_t *game, command_t *c);
void animate_attack(hero_t *h, enemy_t *t, g_t *game);
void counter_attack(g_t *game);
int check_first_incrusted_button(but_t *t, command_t *c);
int check_sec_incrusted_button(but_t *t, command_t *c);
int check_third_incrusted_button(but_t *t, command_t *c);
int check_forth_incrusted_button(but_t *t, command_t *c);
int get_fight_map(char *file, g_t *game);
int search_fight_event(g_t *game, command_t *c);
enemy_t *prepare_inside_sprite(char *str, enemy_t *new);
void draw_background(g_t *game, background_t back);
void move_my_monster_towards(g_t *game, enemy_t *t);
void move_my_monster_backwards(g_t *game, enemy_t *t);
void move_my_hero_backwards(g_t *game, hero_t *h, sfVector2f herop);
void move_my_hero_forwards(g_t *game, hero_t *h);
void get_impact_monster(g_t *game, enemy_t *t);
void draw_my_real_game(g_t *game);
void clear_framebuffer(t_framebuffer *bf, t_window *utils);
void hero_take_damage(int attack, lifebar_t *lifebar);
void draw_my_game(g_t *game);
int my_loading_screen(g_t *g, sfVideoMode mode);
void add_text(g_t *game);
void draw_credits(game_t *game);
t_framebuffer *framebuffer_create(unsigned int width, unsigned int height);
int my_loop_balance_x(t_framebuffer *f, t_circle *p, t_window *u, g_t *game);
int check_clock(g_t *game);
int fight(int mark);
int draw_moving_balance(t_framebuffer *bf, sfVector2i center, int radius);
int search_event_fight(g_t *game, command_t *c);
int open_sec_window(g_t *g);
int five_case(g_t *game, int mark);
int four_case(g_t *game, int mark);
int third_case(g_t *game, int mark);
int seconds_case(g_t *game, int mark);
int firsts_case(g_t *game, int mark);
void set_color_two(text_t *text);
void set_color(text_t *text);
void set_font(text_t *text);
char *save_val_nine(game_t *game);
char *save_last(game_t *game);
