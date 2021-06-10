/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** init_pnj.c
*/

#include <stdlib.h>
#include "town.h"
#include "building_pos.h"

static const char *path_pnj[] = {"assets/img/pnj/master/master_walk.png",
                            "assets/img/pnj/vilager_one/vilager_one_walk.png",
                            "assets/img/pnj/vilager_two/vilager_two_walk.png"};

static const sfVector2f pnj_scale = {.x = 1.2f, .y = 1.2f};

static const char *path_e = "assets/img/town/e.png";

int init_e(town_t *town)
{

    town->e.texture = sfTexture_createFromFile(path_e, NULL);
    town->e.sprite = sfSprite_create();
    if (!town->e.sprite || !town->e.texture)
        return -1;
    sfSprite_setTexture(town->e.sprite, town->e.texture, 0);
    town->e.pos = (sfVector2f){.x = town->pnj[0].pos.x + town->bg.pos.x ,
                            .y = town->pnj[0].pos.y + town->bg.pos.y};
    sfSprite_setPosition(town->e.sprite, town->e.pos);
    town->e.scale = (sfVector2f){0.5f, 0.5f};
    sfSprite_setScale(town->e.sprite, town->e.scale);
    return 0;
}

int init_pnj(town_t *town)
{
    town->pnj = malloc(sizeof(object_t) * n_png);
    if (!town->pnj)
        return -1;
    for (sfUint32 i = 0; i < n_png; ++i) {
        town->pnj[i].texture = sfTexture_createFromFile(path_pnj[i], NULL);
        town->pnj[i].sprite = sfSprite_create();
        if (!town->pnj[i].sprite || !town->pnj[i].texture)
            return -1;
        sfSprite_setTexture(town->pnj[i].sprite, town->pnj[i].texture, 0);
        town->pnj[i].pos = pos_pnj[i];
        town->pnj[i].scale = pnj_scale;
        town->pnj[i].rect.rect = (sfIntRect){47, 0, 47, 48};
        sfSprite_setPosition(town->pnj[i].sprite, town->pnj[i].pos);
        sfSprite_setScale(town->pnj[i].sprite, town->pnj[i].scale);
        sfSprite_setTextureRect(town->pnj[i].sprite, town->pnj[i].rect.rect);
    }
    init_e(town);
    return 0;
}