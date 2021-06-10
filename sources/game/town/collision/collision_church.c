/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** collision_hdv_church.c
*/

#include "building_pos.h"
#include "town.h"

void default_side(sfFloatRect *f_rect, sfInt8 side);

static sfBool colli_corner(const sfFloatRect player, const sfFloatRect church)
{
    if ((player.top + player.height < church.top + 150.0 &&
    player.left + player.width < church.left + 150.0) ||
    (player.top + player.height  < church.top + 150.0 &&
    player.left > church.left + church.width - 150.0) ||
    (player.top > church.top + church.height - 178.0 &&
    player.left + player.width < church.left + 140.0) ||
    (player.top > church.top + church.height - 178.0 &&
    player.left > church.left + church.width - 150.0))
        return sfTrue;
    return sfFalse;
}

sfBool collision_church(town_t *town, sfInt8 side)
{
    sfFloatRect player = sfSprite_getGlobalBounds(town->player.sprite);
    sfFloatRect church = sfSprite_getGlobalBounds(town->church.sprite);

    player.left += 10;
    player.width -= 20;
    church.top += 200;
    church.height -= 200;
    church.width -= 15;
    default_side(&church, side);
    if (colli_corner(player, church))
        return sfFalse;
    if (sfFloatRect_intersects(&player, &church, &church))
        return sfTrue;
    return sfFalse;
}