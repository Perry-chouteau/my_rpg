/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** init_inventory.c
*/

#include "myself.h"

static const char *path_inventory = "assets/img/myself/inventory.png";

static const char *path_items[] = {"assets/img/town/quest/mushroom.png",
                                    "assets/img/town/quest/mushroom.png",
                                    "assets/img/town/quest/mushroom.png",
                                    "assets/img/town/quest/mushroom.png",
                                    "assets/img/town/quest/mushroom.png",
                                    "assets/img/town/quest/wine.png",
                                    "assets/img/town/quest/wine.png",
                                    "assets/img/town/quest/wine.png",
                                    "assets/img/town/quest/wine.png",
                                    "assets/img/town/quest/wine.png",
                                    "assets/img/myself/items/sword.png",
                                    "assets/img/myself/items/chest.png",
                                    "assets/img/myself/items/gloves.png",
                                    "assets/img/myself/items/pants.png",
                                    "assets/img/myself/items/boots.png"};

static const sfVector2f pos_item[] = {  {140, 600},
                                        {220, 600},
                                        {300, 600},
                                        {380, 600},
                                        {460, 600},
                                        {135, 700},
                                        {215, 700},
                                        {295, 700},
                                        {375, 700},
                                        {455, 700},
                                        {115, 750},
                                        {195, 750},
                                        {275, 750},
                                        {355, 750},
                                        {435, 750}};

int init_items(item_t *items)
{
    for (int i = 0; i < item_max; ++i) {
        items[i].display = false;
        items[i].sprite = sfSprite_create();
        if (!items[i].sprite)
            return -1;
        items[i].texture = sfTexture_createFromFile(path_items[i], NULL);
        if (!items[i].texture)
            return -1;
        items[i].pos = pos_item[i];
        sfSprite_setTexture(items[i].sprite, items[i].texture, 0);
        sfSprite_setPosition(items[i].sprite, items[i].pos);
        if (i < 5)
            sfSprite_setScale(items[i].sprite, (sfVector2f){1, 1});
        else
            sfSprite_setScale(items[i].sprite, (sfVector2f){0.5f, 0.5f});
    }
    items[10].display = true;
    return 0;
}

int init_inventory(object_t *inventory)
{
    inventory->sprite = sfSprite_create();
    if (!inventory->sprite)
        return -1;
    inventory->texture = sfTexture_createFromFile(path_inventory, NULL);
    if (!inventory->texture)
        return -1;
    inventory->pos = (sfVector2f){100, 500};
    inventory->scale = (sfVector2f){2, 2};
    sfSprite_setTexture(inventory->sprite, inventory->texture, 0);
    sfSprite_setPosition(inventory->sprite, inventory->pos);
    sfSprite_setScale(inventory->sprite, inventory->scale);
    return 0;
}