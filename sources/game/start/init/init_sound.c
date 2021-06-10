/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** init_sound.c
*/

#include "my_rpg.h"

static char *path_sound[] = {"assets/sounds/hover_sfx.ogg",
                        "assets/sounds/onclick_sfx.ogg"};

static char *path_music[] = {"assets/sounds/theme.ogg",
                                "assets/sounds/rain.ogg"};

static void init_music(sound_t *sound)
{
        sound->music_volume = 10;
        sound->buffer_music_volume = sound->music_volume;
        sound->music = sfMusic_createFromFile(path_music[0]);
        sound->rain = sfMusic_createFromFile(path_music[1]);
        sfMusic_play(sound->music);
        sfMusic_setLoop(sound->music, sfTrue);
        sfMusic_setLoop(sound->rain, sfTrue);
        sfMusic_setVolume(sound->music, sound->music_volume);
        sfMusic_setVolume(sound->rain, sound->music_volume);
        sound->mute_status = 0;
}

void init_sound(sound_t *sound)
{
    init_music(sound);
    sound->hover_sfx = sfSound_create();
    sound->onclick_sfx = sfSound_create();
    sound->hover_sfx_buffer = sfSoundBuffer_createFromFile(path_sound[0]);
    sound->onclick_sfx_buffer = sfSoundBuffer_createFromFile(path_sound[1]);
    sfSound_setBuffer(sound->hover_sfx, sound->hover_sfx_buffer);
    sfSound_setBuffer(sound->onclick_sfx, sound->onclick_sfx_buffer);
    sfSound_setVolume(sound->onclick_sfx, 10);
}
