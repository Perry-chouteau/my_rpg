/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** init_bg.c
*/

#include "town.h"

static const char *bg_sprite = "assets/img/town/map/bg.png";
static const sfVector2f bg_pos = {.x =  150, .y = -1750};
static const sfVector2f bg_scale = {.x = 1, .y = 1};

int init_bg(town_t *town)
{
    town->bg.pos = bg_pos;
    town->bg.scale = bg_scale;
    town->bg.sprite = sfSprite_create();
    if (town->bg.sprite == NULL)
        return -1;
    town->bg.texture = sfTexture_createFromFile(bg_sprite, NULL);
    sfSprite_setTexture(town->bg.sprite, town->bg.texture, sfFalse);
    sfSprite_setPosition(town->bg.sprite, town->bg.pos);
    sfSprite_setScale(town->bg.sprite, town->bg.scale);
    return 0;
}