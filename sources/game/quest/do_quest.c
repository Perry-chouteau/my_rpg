/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** do_quest.c
*/

#include "town.h"
#include "my_rpg.h"
#include "building_pos.h"

void draw_mushroom(window_t *window, town_t *town, myself_t *myself);

void draw_wine(window_t *window, town_t *town, myself_t *myself);

int draw_fight_e(window_t *window, town_t *town, myself_t *myself);

void call_fight_e(window_t *window, town_t *town, myself_t *myself)
{
        sfFloatRect player = sfSprite_getGlobalBounds(town->player.sprite);
        sfFloatRect pnj = sfSprite_getGlobalBounds(town->pnj[0].sprite);
        pnj.left -= 20;
        pnj.top  -= 20;
        pnj.height += 40;
        pnj.width  += 40;
        if (sfFloatRect_intersects(&player, &pnj, &pnj))
            draw_fight_e(window, town, myself);
}

int do_quest(window_t *window, town_t *town, myself_t *myself)
{
    if (myself->level == 1) {
        draw_mushroom(window, town, myself);
        if (myself->items[0].display && myself->items[1].display &&
        myself->items[2].display && myself->items[3].display &&
        myself->items[4].display)
            ++myself->level;
    } else if (myself->level == 2) {
        draw_wine(window, town, myself);
        if (myself->items[5].display && myself->items[6].display &&
        myself->items[7].display && myself->items[8].display &&
        myself->items[9].display)
            ++myself->level;
    }
    if (myself->level == 3)
        call_fight_e(window, town, myself);
    myself->score[2] = my_itoa(myself->level);
    sfText_setString(myself->nb_score[2], myself->score[2]);
    sfRenderWindow_setMouseCursorVisible(window->window, 0);
    return 0;
}
