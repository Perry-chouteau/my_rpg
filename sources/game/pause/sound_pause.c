/*
** EPITECH PROJECT, 2021
** sound_settings
** File description:
** sound_settings
*/

#include "my_rpg.h"

void play_pause_sound_hover(pause_t *pause, sound_t *sound)
{
    if (pause->over_sound_status == 0 && sound->mute_status == 0) {
        pause->over_sound_status = 1;
        sfSound_play(sound->hover_sfx);
    }
}