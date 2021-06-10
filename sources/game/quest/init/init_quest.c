/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** init_quest.c
*/

#include <stdlib.h>
#include "town.h"
#include "my_rpg.h"
#include "building_pos.h"

static const sfVector2f no_scale = {.x = 1, .y = 1};

static const char *path_shrom = "assets/img/town/quest/mushroom.png";

static const char *path_wine = "assets/img/town/quest/wine.png";

int init_mushroom(town_t *town)
{
    town->mushroom = malloc(sizeof(object_t) * n_mushroom);
    for (sfUint32 i = 0; i < n_mushroom; ++i) {
        town->mushroom[i].texture = sfTexture_createFromFile(path_shrom, NULL);
        if (!town->mushroom[i].texture)
            return -1;
        town->mushroom[i].sprite = sfSprite_create();
        if (!town->mushroom[i].sprite)
            return -1;
        sfSprite_setTexture(town->mushroom[i].sprite,    \
                            town->mushroom[i].texture, 0);
        town->mushroom[i].pos = pos_mushroom[i];
        town->mushroom[i].scale = no_scale;
        sfSprite_setScale(town->mushroom[i].sprite, no_scale);
    }
    return 0;
}

int init_wine(town_t *town)
{
    town->wine = malloc(sizeof(object_t) * n_wine);
    for (sfUint32 i = 0; i < n_wine; ++i) {
        town->wine[i].texture = sfTexture_createFromFile(path_wine, NULL);
        if (!town->mushroom[i].texture)
            return -1;
        town->wine[i].sprite = sfSprite_create();
        if (!town->mushroom[i].sprite)
            return -1;
        sfSprite_setTexture(town->wine[i].sprite,   \
                            town->wine[i].texture, 0);
        town->wine[i].pos = pos_wine[i];
        town->wine[i].scale = no_scale;
        sfSprite_setScale(town->wine[i].sprite, no_scale);
    }
    return 0;
}