/*
** EPITECH PROJECT, 2021
** input_settings
** File description:
** input_settings
*/

#include "my_rpg.h"

int pause_bag(int *i)
{
    static int n = -1;

    if (i)
        n = *i;
    return n;
}

void check_pause_onclick(window_t *window, pause_t *pause,
sfEvent *event, sound_t *sound)
{
    int i = pause_bag(NULL);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSprite_setPosition(pause->view[BANNER_ONCLICK_].sprite,
        settings_view_pos[i]);
        sfSprite_setPosition(pause->view[BANNER_HOVER_].sprite,
        settings_view_pos[9]);
        if (sound->mute_status == 0)
            sfSound_play(sound->onclick_sfx);
    }
    if (event->mouseButton.button == sfMouseLeft
    && event->type == sfEvtMouseButtonReleased) {
        window->status = pause_status[i - 1];
        sfSprite_setPosition(pause->view[BANNER_ONCLICK_].sprite,
        settings_view_pos[9]);
        if (window->status == TUTO) {
            window->previous_status = PAUSE;
            do_tuto(window);
        }
    }
}