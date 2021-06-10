/*
** EPITECH PROJECT, 2021
** do_skill_tree
** File description:
** do_skill_tree
*/

#include "my_rpg.h"
#include "myself.h"

void do_skill(window_t *window, myself_t *myself, sfEvent *event)
{
    static int i = 1;
    sfVector2i curs = sfMouse_getPositionRenderWindow(window->window);

    if (event->type == CLICK_RELEASED && i < myself->level && myself->display) {
        if (curs.x > 680 && curs.x < 780 && curs.y > 400 && curs.y < 500) {
            myself->life += 10;
            myself->score[0] = my_itoa(myself->life);
            sfText_setString(myself->nb_score[0], myself->score[0]);
            event->type = CLICK_PRESS;
            i += 1;
        }
        if (curs.x > 1180 && curs.x < 1280 && curs.y > 400 && curs.y < 500) {
            myself->damage += 10;
            myself->score[1] = my_itoa(myself->damage);
            sfText_setString(myself->nb_score[1], myself->score[1]);
            event->type = CLICK_PRESS;
            i += 1;
        }
    }
}