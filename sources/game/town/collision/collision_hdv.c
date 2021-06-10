/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** collision_hdv_church.c
*/

#include "building_pos.h"
#include "town.h"

void default_side(sfFloatRect *f_rect, sfInt8 side);

static sfBool colli_corner(const sfFloatRect player, const sfFloatRect hdv)
{
    if ((player.top + player.height < hdv.top + 100.0 &&
    player.left + player.width < hdv.left + 115.0) ||
    (player.top + player.height < hdv.top + 100.0 &&
    player.left > hdv.left + hdv.width - 100.0) ||
    (player.top > hdv.top + hdv.height - 100.0 &&
    player.left + player.width < hdv.left + 115.0) ||
    (player.top > hdv.top + hdv.height - 100.0 &&
    player.left > hdv.left + hdv.width - 100.0))
        return sfTrue;
    return sfFalse;
}

sfBool collision_hdv(town_t *town, sfInt8 side)
{
    sfFloatRect player = sfSprite_getGlobalBounds(town->player.sprite);
    sfFloatRect hdv = sfSprite_getGlobalBounds(town->hdv.sprite);
    player.left += 10;
    player.width -= 20;
    hdv.top += 100;
    hdv.height -= 100;
    default_side(&hdv, side);
    if (colli_corner(player, hdv))
        return sfFalse;
    if (sfFloatRect_intersects(&player, &hdv, &hdv))
        return sfTrue;
    return sfFalse;
}