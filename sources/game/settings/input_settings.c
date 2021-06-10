/*
** EPITECH PROJECT, 2021
** input_settings
** File description:
** input_settings
*/

#include "my_rpg.h"

int setting_bag(int *i)
{
    static int n = -1;

    if (i)
        n = *i;
    return n;
}

int check_escape(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        return 1;
    return 0;
}

void check_onclick(window_t *window, settings_t *settings,
sfEvent *event, sound_t *sound)
{
    int i = setting_bag(NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSprite_setPosition(settings->view[BANNER_ONCLICK_].sprite,
        settings_view_pos[i]);
        sfSprite_setPosition(settings->view[BANNER_HOVER_].sprite,
        settings_view_pos[9]);
        if (sound->mute_status == 0)
            sfSound_play(sound->onclick_sfx);
    }
    if (event->mouseButton.button == sfMouseLeft
    && event->type == sfEvtMouseButtonReleased) {
        window->status = settings_status[i - 1];
        sfSprite_setPosition(settings->view[BANNER_ONCLICK_].sprite,
        settings_view_pos[9]);
    }
}

void check_mute_click(sfEvent *event, sound_t *sound)
{
    if (event->mouseButton.button == sfMouseLeft
    && event->type == sfEvtMouseButtonReleased) {
        if (sound->mute_status == 0) {
            sound->music_volume = 0;
            sound->mute_status = 1;
            event->mouseButton.button = sfMouseRight;
            sfMusic_setVolume(sound->music, sound->music_volume);
            return;
        }
        if (sound->mute_status == 1) {
            sound->music_volume = sound->buffer_music_volume;
            sound->mute_status = 0;
            event->mouseButton.button = sfMouseRight;
            sfMusic_setVolume(sound->music, sound->music_volume);
        }
    }
}
