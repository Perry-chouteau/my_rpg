/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** collision_pnj.c
*/

#include "building_pos.h"
#include "town.h"

void default_side(sfFloatRect *f_rect, sfInt8 side);

sfBool collision_pnj(town_t *town, sfInt8 side)
{
    for (sfUint32 i = 0; i < n_png; ++i) {
        sfFloatRect player = sfSprite_getGlobalBounds(town->player.sprite);
        sfFloatRect pnj = sfSprite_getGlobalBounds(town->pnj[i].sprite);
        player.left += 10;
        player.width -= 20;
        pnj.left += 10;
        pnj.width -= 20;
        pnj.top += 42;
        pnj.height -= 42;
        default_side(&pnj, side);
        if (sfFloatRect_intersects(&player, &pnj, &pnj))
            return sfTrue;
    }
    return sfFalse;
}