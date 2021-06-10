/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** destroy.c
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "myself.h"

void destroy_sound(sound_t *sound)
{
    sfMusic_destroy(sound->music);
    sfMusic_destroy(sound->rain);
    sfSound_destroy(sound->hover_sfx);
    sfSound_destroy(sound->onclick_sfx);
    sfSoundBuffer_destroy(sound->hover_sfx_buffer);
    sfSoundBuffer_destroy(sound->onclick_sfx_buffer);
}

void destroy_myself(myself_t *myself)
{
    sfSprite_destroy(myself->face.sprite);
    sfTexture_destroy(myself->face.texture);
    sfSprite_destroy(myself->inventory.sprite);
    sfTexture_destroy(myself->inventory.texture);
    for (int i = 0; i < item_max; ++i) {
        sfSprite_destroy(myself->items[i].sprite);
    }
    free(myself->items);
    sfSprite_destroy(myself->quest.sprite);
    sfTexture_destroy(myself->quest.texture);
}

void destroy_start(window_t *window, sound_t *sound, myself_t *myself)
{
    sfRenderWindow_destroy(window->window);
    destroy_sound(sound);
    destroy_myself(myself);
}