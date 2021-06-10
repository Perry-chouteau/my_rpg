/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** collision_house.c
*/

#include "building_pos.h"
#include "town.h"

sfBool collision_fountain(town_t *town, sfInt8 side)
{
        sfFloatRect player = sfSprite_getGlobalBounds(town->player.sprite);
        sfFloatRect f = sfSprite_getGlobalBounds(town->fountain.sprite);

        f.top += 20;
        f.height -= 20;
        player.left += 10;
        player.width -= 20;
        f.top += 10;
        f.height -= 10;
        if (side == TOP)
            f.top += 6;
        if (side == BOTTOM)
            f.top -= 6;
        if (side == LEFT)
            f.left += 6;
        if (side == RIGHT)
            f.left -= 6;
        if (sfFloatRect_intersects(&player, &f, &f))
            return sfTrue;
    return sfFalse;
}