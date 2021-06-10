/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** draw_town.c
*/

#include "my_rpg.h"
#include "town.h"
#include "building_pos.h"

void draw_church(window_t *window, town_t *town);

void draw_hdv(window_t *window, town_t *town);

void draw_house_horizontal(window_t *window, town_t *town);

void draw_house_vertical(window_t *window, town_t *town);

void draw_fountain(window_t *window, town_t *town);

int draw_pnj(window_t *window, town_t *town);

void draw_mouse(window_t *window, town_t *town);

void draw_myself(window_t *window, myself_t *myself);

int do_quest(window_t *window, town_t *town, myself_t *myself);

int draw_town(window_t *window, town_t *town, myself_t *myself)
{
    sfRenderWindow_drawSprite(window->window, town->bg.sprite, NULL);
    do_quest(window, town, myself);
    sfRenderWindow_drawSprite(window->window, town->player.sprite, NULL);
    draw_hdv(window, town);
    draw_church(window, town);
    draw_house_vertical(window, town);
    draw_house_horizontal(window, town);
    draw_fountain(window, town);
    draw_pnj(window, town);
    if (myself->display)
        draw_myself(window, myself);
    draw_mouse(window, town);
    return 0;
}