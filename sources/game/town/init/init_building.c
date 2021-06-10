/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** init_building.c
*/

#include <stdlib.h>
#include "town.h"
#include "building_pos.h"

static const sfVector2f no_scale = {.x = 1, .y = 1};

static const char *path_church = "assets/img/town/map/eglise.png";
static const char *path_hdv = "assets/img/town/map/hdv.png";
static const char *path_fountain = "assets/img/town/map/fountain.png";
static const char *path_h = "assets/img/town/map/house horizontal.png";
static const char *path_v = "assets/img/town/map/house vertical.png";

int init_hdv(town_t *town)
{
    town->hdv.texture = sfTexture_createFromFile(path_hdv, NULL);
    town->hdv.sprite = sfSprite_create();
    sfSprite_setTexture(town->hdv.sprite, town->hdv.texture, 0);
    town->hdv.pos = (sfVector2f){pos_hdv.x, pos_hdv.y};
    town->hdv.scale = no_scale;
    sfSprite_setPosition(town->hdv.sprite, town->hdv.pos);
    return 0;
}

int init_church(town_t *town)
{
    town->church.texture = sfTexture_createFromFile(path_church, NULL);
    town->church.sprite = sfSprite_create();
    sfSprite_setTexture(town->church.sprite, town->church.texture, 0);
    town->church.pos = (sfVector2f){pos_church.x, pos_church.y};
    town->church.scale = no_scale;
    sfSprite_setPosition(town->church.sprite, town->church.pos);
    return 0;
}

int init_horizontal_house(town_t *town)
{
    town->house_h = malloc(sizeof(object_t) * n_h_h);
    for (sfUint32 i = 0; i < n_h_h; ++i) {
        town->house_h[i].texture = sfTexture_createFromFile(path_h, NULL);
        town->house_h[i].sprite = sfSprite_create();
        sfSprite_setTexture(town->house_h[i].sprite,    \
                            town->house_h[i].texture, 0);
        town->house_h[i].pos = pos_house_h[i];
        town->house_h[i].scale = no_scale;
        sfSprite_setScale(town->house_h[i].sprite, no_scale);
    }
    return 0;
}

int init_vertical_house(town_t *town)
{
    town->house_v = malloc(sizeof(object_t) * n_h_v);
    for (sfUint32 i = 0; i <  n_h_v; ++i) {
        town->house_v[i].texture = sfTexture_createFromFile(path_v, NULL);
        town->house_v[i].sprite = sfSprite_create();
        sfSprite_setTexture(town->house_v[i].sprite,    \
                            town->house_v[i].texture, 0);
        town->house_v[i].pos = pos_house_v[i];
        town->house_v[i].scale = no_scale;
        sfSprite_setScale(town->house_v[i].sprite, no_scale);
    }
    return 0;
}

int init_fountain(town_t *town)
{
    town->fountain.texture = sfTexture_createFromFile(path_fountain, NULL);
    town->fountain.sprite = sfSprite_create();
    sfSprite_setTexture(town->fountain.sprite, town->fountain.texture, 0);
    town->fountain.pos = (sfVector2f){pos_fountain.x, pos_fountain.y};
    town->fountain.scale = no_scale;
    sfSprite_setPosition(town->fountain.sprite, town->fountain.pos);
    town->fountain.rect.rect = (sfIntRect){0, 0, 125, 124};
    return 0;
}