/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** draw_inventory.c
*/

#include "my_rpg.h"
#include "myself.h"
#include <stdio.h>

static const sfVector2f pos_score[] = {{450, 198},
{470, 260},
{470, 322}};

int draw_myself(window_t *window, myself_t *myself)
{
    int lvl = myself->level;

    RW_DRAW(window->window, myself->face.sprite, NULL);
    for (int i = 0; i < 3; i++) {
        sfText_setPosition(myself->nb_score[i], pos_score[i]);
        sfRenderWindow_drawText(window->window, myself->nb_score[i], NULL);
    }
    RW_DRAW(window->window, myself->quest.sprite, NULL);
    sfRenderWindow_drawText(window->window, myself->text_quest[lvl - 1], NULL);
    RW_DRAW(window->window, myself->inventory.sprite, NULL);
    RW_DRAW(window->window, myself->skill_tree.sprite, NULL);

    for (int i = 0; i < item_max; ++i)
        if (myself->items[i].display)
            RW_DRAW(window->window, myself->items[i].sprite, NULL);
    return 0;
}
