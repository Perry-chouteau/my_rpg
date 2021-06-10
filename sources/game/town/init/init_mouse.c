/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** init_mouse.c
*/

#include "town.h"

static const char *path_mouse = "assets/img/mouse.png";
static const sfVector2f mouse_scale = {0.05, 0.05};

int init_mouse(town_t *town)
{
    town->mouse.scale = mouse_scale;
    town->mouse.sprite = sfSprite_create();
    if (town->mouse.sprite == NULL)
        return -1;
    town->mouse.texture = sfTexture_createFromFile(path_mouse, NULL);
    sfSprite_setTexture(town->mouse.sprite, town->mouse.texture, sfFalse);
    sfSprite_setScale(town->mouse.sprite, town->mouse.scale);
    return 0;
}