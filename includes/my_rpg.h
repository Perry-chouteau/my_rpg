/*
** EPITECH PROJECT, 2021
** my_defender.h
** File description:
** header of my_rpg
*/

#ifndef _MY_RPG_H_
#define _MY_RPG_H_

#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdbool.h>

#include "town.h"
#include "myself.h"
#include "menu.h"
#include "pause.h"
#include "tutorial.h"
#include "settings.h"
#include "fight/fight.h"
#include "history/history.h"

#define KEY_PRESS sfKeyboard_isKeyPressed
#define RW_DRAW sfRenderWindow_drawSprite

typedef enum {
    ERR = -1,
    END,
    TUTO,
    MENU,
    SETTINGS,
    TOWN,
    FIGHT,
    BOSS,
    PAUSE,
    CONV,
}status_e;

static const int settings_status[3] = {TUTO, END, MENU};
static const int pause_status[4] = {TUTO, END, TOWN, MENU};

typedef struct sound_s {
    sfMusic *music;
    sfMusic *rain;
    float music_volume;
    float buffer_music_volume;
    int mute_status;
    sfSound *hover_sfx;
    sfSoundBuffer *hover_sfx_buffer;
    sfSound *onclick_sfx;
    sfSoundBuffer *onclick_sfx_buffer;
}sound_t;

typedef struct window_s {
    sfRenderWindow *window;
    status_e status;
    status_e previous_status;
}window_t;

int start(int fps);

int init_town(town_t *town);
int init_menu(menu_t *menu);
int init_tuto(tuto_t *tuto);
int init_settings(settings_t *settings);

void do_myself(myself_t *myself);
int do_menu(window_t *window, sound_t *sound);
int do_town(window_t *window, myself_t *myself, sound_t *sound);
int do_tuto(window_t *window);
int do_settings(window_t *window, sound_t *sound);
bool do_fight(window_t *window, myself_t *myself);

int destroy_tuto(tuto_t *tuto);
int destroy_settings(settings_t *settings);
void my_event(sfEvent *event, window_t *window);
void analyse_events(window_t *window, fight_t *fight);

/* fight */
void finished(window_t *window, fight_t *fight);
void draw_hp(window_t *window, character_t *character);
char *my_itoa(int nbr);

/* settings */
int check_escape(void);
void check_mute_click(sfEvent *event, sound_t *sound);
void check_onclick(window_t *window, settings_t *settings,
sfEvent *event, sound_t *sound);
void change_volume(sound_t *sound, int volume_status);
void move_banner(window_t *window, settings_t *settings,
sfEvent *event, sound_t *sound);
void move_muted_icon(window_t *window, settings_t *settings,
sfEvent *event, sound_t *sound);
void scale_icons(window_t *window, settings_t *settings,
sound_t *sound, sfEvent *event);
void check_event_volume(sound_t *sound);
void play_sound_hover(settings_t *settings, sound_t *sound);

/* pause */
void move_pause_banner(window_t *window, pause_t *pause,
sfEvent *event, sound_t *sound);
void move_pause_muted_icon(window_t *window, pause_t *pause,
sfEvent *event, sound_t *sound);
void scale_pause_icons(window_t *window, pause_t *pause,
sound_t *sound, sfEvent *event);
int do_pause(window_t *window, sound_t *sound);
int init_pause(window_t *window, pause_t *pause);
int destroy_pause(pause_t *pause);
void check_pause_onclick(window_t *window, pause_t *pause,
sfEvent *event, sound_t *sound);
void play_pause_sound_hover(pause_t *pause, sound_t *sound);

void animation_fight(window_t *window);
int do_conv(window_t *window);
int my_init_text(sfText ***text, int nb_text);
char **str_to_wordtab(char const *str, char sep);
int pause_bag(int *i);
#endif /* _MY_RPG_H_ */