/*
** EPITECH PROJECT, 2021
** sound_settings
** File description:
** sound_settings
*/

#include "my_rpg.h"

void check_event_volume(sound_t *sound)
{
    if (sfKeyboard_isKeyPressed(sfKeyAdd))
        if (sound->music_volume <= 98) {
            sound->buffer_music_volume += 2;
            sound->music_volume = sound->buffer_music_volume;
            sfMusic_setVolume(sound->music, sound->music_volume);
        }
    if (sfKeyboard_isKeyPressed(sfKeySubtract))
        if (sound->music_volume >= 2) {
            sound->buffer_music_volume -= 2;
            sound->music_volume = sound->buffer_music_volume;
            sfMusic_setVolume(sound->music, sound->music_volume);
        }
}

void change_volume(sound_t *sound, int volume_status)
{
    if (volume_status == 4) {
        if (sound->music_volume >= 2) {
            sound->buffer_music_volume -= 2;
            sound->music_volume = sound->buffer_music_volume;
            sfMusic_setVolume(sound->music, sound->music_volume);
        }
    } else {
        if (sound->music_volume <= 98) {
            sound->buffer_music_volume += 2;
            sound->music_volume = sound->buffer_music_volume;
            sfMusic_setVolume(sound->music, sound->music_volume);
        }
    }
}

void play_sound_hover(settings_t *settings, sound_t *sound)
{
    if (settings->over_sound_status == 0 && sound->mute_status == 0) {
        settings->over_sound_status = 1;
        sfSound_play(sound->hover_sfx);
    }
}