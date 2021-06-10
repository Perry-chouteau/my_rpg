/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** check_collision.c
*/

#include "my_rpg.h"
#include "building_pos.h"

sfBool collision_church(town_t *town, sfInt8 side);

sfBool collision_hdv(town_t *town, sfInt8 side);

sfBool collision_house_horizontal(town_t *town, sfInt8 side);

sfBool collision_house_vertical(town_t *town, sfInt8 side);

sfBool collision_fountain(town_t *town, sfInt8 side);

sfBool collision_pnj(town_t *town, sfInt8 side);

void default_side(sfFloatRect *f_rect, sfInt8 side)
{
    if (side == TOP)
        f_rect->top += 6;
    if (side == BOTTOM)
        f_rect->top -= 6;
    if (side == LEFT)
        f_rect->left += 6;
    if (side == RIGHT)
        f_rect->left -= 6;
}

sfBool colision_ext_bg(town_t *town, sfInt8 side)
{
    if (side == TOP && town->bg.pos.y > ext_bg_pos[1].y - 3)
        return sfTrue;
    if (side == BOTTOM && town->bg.pos.y < ext_bg_pos[0].y + 3)
        return sfTrue;
    if (side == LEFT && town->bg.pos.x > ext_bg_pos[1].x - 3)
        return sfTrue;
    if (side == RIGHT && town->bg.pos.x < ext_bg_pos[0].x + 3)
        return sfTrue;
    return sfFalse;
}

sfBool collision_building(town_t *town, sfInt8 side)
{
    if (colision_ext_bg(town, side))
        return sfFalse;
    if (collision_church(town, side))
        return sfFalse;
    if (collision_hdv(town, side))
        return sfFalse;
    if (collision_house_horizontal(town, side))
        return sfFalse;
    if (collision_house_vertical(town, side))
        return sfFalse;
    if (collision_fountain(town, side))
        return sfFalse;
    if (collision_pnj(town, side))
        return sfFalse;
    return sfTrue;
}