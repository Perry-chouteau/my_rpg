/*
** EPITECH PROJECT, 2021
** init_town
** File description:
** init_town
*/

#include "my_rpg.h"

int init_hdv(town_t *town);

int init_church(town_t *town);

int init_mouse(town_t *town);

int init_horizontal_house(town_t *town);

int init_vertical_house(town_t *town);

int init_fountain(town_t *town);

int init_bg(town_t *town);

int init_player(town_t *town);

int init_pnj(town_t *town);

int init_fountain(town_t *town);

int init_mushroom(town_t *town);

int init_wine(town_t *town);

int init_town(town_t *town)
{
    if (init_bg(town) || init_player(town) || init_mouse(town))
        return -1;
    if (init_hdv(town) || init_church(town))
        return -1;
    if (init_horizontal_house(town) || init_vertical_house(town))
        return -1;
    if (init_fountain(town) || init_pnj(town))
        return -1;
    if (init_mushroom(town) || init_wine(town))
        return -1;
    return 0;
}