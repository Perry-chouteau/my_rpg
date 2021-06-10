/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** start.c
*/

#include "my_rpg.h"
#include "myself.h"

int init_window(window_t *windows, int fps);

int init_myself(myself_t *myself);

void init_sound(sound_t *sound);

void destroy_start(window_t *window, sound_t *sound, myself_t *myself);

void while_status(window_t *window, sound_t *sound, myself_t *myself)
{
    while (sfRenderWindow_isOpen(window->window)) {
        if (window->status == TUTO)
            do_tuto(window);
        if (window->status == MENU)
            do_menu(window, sound);
        if (window->status == SETTINGS)
            do_settings(window, sound);
        if (window->status == PAUSE)
            do_pause(window, sound);
        if (window->status == TOWN)
            do_town(window, myself, sound);
        if (window->status == END || window->status == ERR)
            sfRenderWindow_close(window->window);
        if (window->status == CONV)
            do_conv(window);
    }
}

int start(int fps)
{
    window_t window;
    sound_t sound = {0};
    myself_t myself = {0};

    if (!fps || init_window(&window, fps) || init_myself(&myself))
        return 84;
    init_sound(&sound);
    while_status(&window, &sound, &myself);
    destroy_start(&window, &sound, &myself);
    if (window.status == ERR)
        return 84;
    else
        return 0;
}