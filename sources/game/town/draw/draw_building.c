/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** draw_building.c
*/

#include "my_rpg.h"
#include "building_pos.h"

void draw_church(window_t *window, town_t *town)
{
    sfVector2f pos = (sfVector2f){town->church.pos.x + town->bg.pos.x, \
                                town->church.pos.y + town->bg.pos.y};
    sfSprite_setPosition(town->church.sprite, pos);
    sfRenderWindow_drawSprite(window->window, town->church.sprite, NULL);
}

void draw_hdv(window_t *window, town_t *town)
{
    sfVector2f pos = (sfVector2f){town->hdv.pos.x + town->bg.pos.x, \
                                town->hdv.pos.y + town->bg.pos.y};
    sfSprite_setPosition(town->hdv.sprite, pos);
    sfRenderWindow_drawSprite(window->window, town->hdv.sprite, NULL);
}

void draw_house_horizontal(window_t *window, town_t *town)
{
    for (sfUint32 i = 0; i < n_h_h; ++i) {
    sfVector2f pos = (sfVector2f){town->house_h[i].pos.x + town->bg.pos.x, \
                                town->house_h[i].pos.y + town->bg.pos.y};
    sfSprite_setPosition(town->house_h[i].sprite, pos);
    sfRenderWindow_drawSprite(window->window, town->house_h[i].sprite, NULL);
    }
}

void draw_house_vertical(window_t *window, town_t *town)
{
    for (sfUint32 i = 0; i < n_h_v; ++i) {
    sfVector2f pos = (sfVector2f){town->house_v[i].pos.x + town->bg.pos.x, \
                                town->house_v[i].pos.y + town->bg.pos.y};
    sfSprite_setPosition(town->house_v[i].sprite, pos);
    sfRenderWindow_drawSprite(window->window, town->house_v[i].sprite, NULL);
    }
}

void draw_fountain(window_t *window, town_t *town)
{
    sfVector2f pos = (sfVector2f){town->fountain.pos.x + town->bg.pos.x, \
                                town->fountain.pos.y + town->bg.pos.y};
    sfSprite_setPosition(town->fountain.sprite, pos);
    sfRenderWindow_drawSprite(window->window, town->fountain.sprite, NULL);
}
