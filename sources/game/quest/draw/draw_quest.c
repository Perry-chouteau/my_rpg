/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** draw_quest.c
*/

#include "town.h"
#include "my_rpg.h"
#include "building_pos.h"
#include <stdio.h>

void collision_mush(window_t *window, town_t *town, sfUint32 i,
    myself_t *myself)
{
    sfVector2f pos;

    sfFloatRect player = sfSprite_getGlobalBounds(town->player.sprite);
    sfFloatRect mush = sfSprite_getGlobalBounds(town->mushroom[i].sprite);
    player.left += 10;
    player.width -= 20;
    mush.left += 10;
    mush.width -= 20;
    mush.top += 42;
    mush.height -= 42;
    if (sfFloatRect_intersects(&player, &mush, &mush)) {
        pos = (sfVector2f) {.x = town->mushroom[i].pos.x + town->bg.pos.x - 35,
                .y = town->mushroom[i].pos.y + town->bg.pos.y - 35};
        sfSprite_setPosition(town->e.sprite, pos);
        if (KEY_PRESS(sfKeyE))
            myself->items[i].display = sfTrue;
        if (myself->items[i].display == sfFalse)
            sfRenderWindow_drawSprite(window->window, town->e.sprite, NULL);
    }
}

void collision_wine(window_t *window, town_t *town, sfUint32 i,
    myself_t *myself)
{
    sfVector2f pos;

    sfFloatRect player = sfSprite_getGlobalBounds(town->player.sprite);
    sfFloatRect wine = sfSprite_getGlobalBounds(town->wine[i].sprite);
    player.left += 10;
    player.width -= 20;
    wine.left += 10;
    wine.width -= 20;
    wine.top += 42;
    wine.height -= 42;
    if (sfFloatRect_intersects(&player, &wine, &wine)) {
        pos = (sfVector2f) {.x = town->wine[i].pos.x + town->bg.pos.x - 35,
                .y = town->wine[i].pos.y + town->bg.pos.y - 35};
        sfSprite_setPosition(town->e.sprite, pos);
        if (KEY_PRESS(sfKeyE))
            myself->items[5 + i].display = sfTrue;
        if (myself->items[5 + i].display == sfFalse)
            sfRenderWindow_drawSprite(window->window, town->e.sprite, NULL);
    }
}

void draw_mushroom(window_t *window, town_t *town, myself_t *myself)
{
    sfUint32 i;

    for (i = 0; i < n_mushroom; ++i) {
        if (!myself->items[i].display) {
            sfVector2f pos = (sfVector2f) {town->mushroom[i].pos.x +
            town->bg.pos.x, town->mushroom[i].pos.y + town->bg.pos.y};
            sfSprite_setPosition(town->mushroom[i].sprite, pos);
            sfRenderWindow_drawSprite(window->window,
                                        town->mushroom[i].sprite, NULL);
        }
        collision_mush(window, town, i, myself);
    }
}

void draw_wine(window_t *window, town_t *town, myself_t *myself)
{
    for (sfUint32 i = 0; i < n_wine; ++i) {
        if (!myself->items[5 + i].display) {
            sfVector2f pos = (sfVector2f) {town->wine[i].pos.x +
            town->bg.pos.x, town->wine[i].pos.y + town->bg.pos.y};
            sfSprite_setPosition(town->wine[i].sprite, pos);
            sfRenderWindow_drawSprite(window->window,
                                        town->wine[i].sprite, NULL);
        }
        collision_wine(window, town, i, myself);
    }
}

int draw_fight_e(window_t *window, town_t *town, myself_t *myself)
{
    town->e.pos = (sfVector2f){.x = town->pnj[0].pos.x + town->bg.pos.x - 125,
                            .y = town->pnj[0].pos.y + town->bg.pos.y + 75};
    sfSprite_setPosition(town->e.sprite, town->e.pos);
    sfRenderWindow_drawSprite(window->window, town->e.sprite, NULL);
    if (KEY_PRESS(sfKeyE)) {
        window->status = FIGHT;
        if (do_fight(window, myself) == sfFalse)
            return -1;
        ++myself->level;
        for (sfUint8 i = 11; i < item_max; ++i)
            myself->items[i].display = sfTrue;
    }
    return 0;
}
