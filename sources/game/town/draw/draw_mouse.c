/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** draw_mouse.c
*/

#include "my_rpg.h"
#include "town.h"

void draw_mouse(window_t *window, town_t *town)
{
    sfVector2i v = sfMouse_getPositionRenderWindow(window->window);
    town->mouse.pos.x = (float)v.x;
    town->mouse.pos.y = (float)v.y;
    sfSprite_setPosition(town->mouse.sprite, town->mouse.pos);
    RW_DRAW(window->window, town->mouse.sprite, NULL);
}
