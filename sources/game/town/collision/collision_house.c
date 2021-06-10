/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** collision_house.c
*/

#include "building_pos.h"
#include "town.h"

sfBool collision_house_horizontal(town_t *town, sfInt8 side)
{
    for (sfUint32 i = 0; i < n_h_h; ++i) {
        sfFloatRect player = sfSprite_getGlobalBounds(town->player.sprite);
        sfFloatRect h = sfSprite_getGlobalBounds(town->house_h[i].sprite);
        player.left += 10;
        player.width -= 20;
        h.top += 100;
        h.height -= 100;
        if (side == TOP)
            h.top += 6;
        if (side == BOTTOM)
            h.top -= 6;
        if (side == LEFT)
            h.left += 6;
        if (side == RIGHT)
            h.left -= 6;
        if (sfFloatRect_intersects(&player, &h, &h))
            return sfTrue;
    }
    return sfFalse;
}

sfBool collision_house_vertical(town_t *town, sfInt8 side)
{
    for (sfUint32 i = 0; i < n_h_v; ++i) {
        sfFloatRect player = sfSprite_getGlobalBounds(town->player.sprite);
        sfFloatRect v = sfSprite_getGlobalBounds(town->house_v[i].sprite);
        player.left += 10;
        player.width -= 20;
        v.top += 200;
        v.height -= 200;
        if (side == TOP)
            v.top += 6;
        if (side == BOTTOM)
            v.top -= 6;
        if (side == LEFT)
            v.left += 6;
        if (side == RIGHT)
            v.left -= 6;
        if (sfFloatRect_intersects(&player, &v, &v))
            return sfTrue;
    }
    return sfFalse;
}