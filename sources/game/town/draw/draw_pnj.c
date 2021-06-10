/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** draw_pnj.c
*/

#include "my_rpg.h"
#include "building_pos.h"

int draw_pnj(window_t *window, town_t *town)
{
    for (sfUint32 i = 0; i < n_png; ++i) {
        sfVector2f pos = (sfVector2f){town->pnj[i].pos.x + town->bg.pos.x, \
                                    town->pnj[i].pos.y + town->bg.pos.y};
        sfSprite_setPosition(town->pnj[i].sprite, pos);
        sfRenderWindow_drawSprite(window->window, town->pnj[i].sprite, NULL);
    }
    return 0;
}