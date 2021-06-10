/*
** EPITECH PROJECT, 2021
** events_fight
** File description:
** events_fight
*/

#include <stdlib.h>
#include "my_rpg.h"

static button_status press_button(sfVector2i mouse)
{
    sfVector2i button1 = {(int)POS_BUTTON1.x, (int)POS_BUTTON1.y};
    sfVector2i button2 = {(int)POS_BUTTON2.x, (int)POS_BUTTON2.y};

    if (mouse.x > button1.x - 301 && mouse.x < button1.x + 301
        && mouse.y > button1.y - 49 && mouse.y < button1.y + 49)
        return (BUT1);
    if (mouse.x > button2.x - 301 && mouse.x < button2.x + 301
        && mouse.y > button2.y - 49 && mouse.y < button2.y + 49)
        return (BUT2);
    return (NOTHING);
}

static int mult_damage(void)
{
    int damage = rand()%2;

    if (damage == 0)
        return (LUCK);
    return (0);
}

static void check_button(fight_t *fight, sfVector2i mouse)
{
    button_status button = press_button(mouse);

    if (button == BUT1) {
        sfSprite_setScale(fight->button1.model.spr, (sfVector2f) {0.9f, 0.9f});
        sfText_setScale(fight->button1.text.text, (sfVector2f) {0.9f, 0.9f});
    } else if (button == BUT2) {
        sfSprite_setScale(fight->button2.model.spr, (sfVector2f) {0.9f, 0.9f});
        sfText_setScale(fight->button2.text.text, (sfVector2f) {0.9f, 0.9f});
    } else {
        sfSprite_setScale(fight->button1.model.spr, (sfVector2f) {1, 1});
        sfSprite_setScale(fight->button2.model.spr, (sfVector2f) {1, 1});
        sfText_setScale(fight->button1.text.text, (sfVector2f) {1, 1});
        sfText_setScale(fight->button2.text.text, (sfVector2f) {1, 1});
    }
}

static void do_damage(fight_t *fight, sfVector2i mouse)
{
    fight->button_status = press_button(mouse);

    if (fight->button_status == BUT1) {
        fight->player.attack.play = true;
        fight->enemy.life -= fight->player.damage;
        fight->turn = enemy_turn;
    }
    if (fight->button_status == BUT2) {
        fight->player.attack.play = true;
        fight->enemy.life -= fight->player.damage * mult_damage();
        fight->turn = enemy_turn;
    }
}

void analyse_events(window_t *window, fight_t *fight)
{
    sfEvent event;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);

    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
            window->status = END;
        }
        check_button(fight, mouse);
        if (fight->turn == player_turn && event.type == CLICK_PRESS) {
            do_damage(fight, mouse);
            sfClock_restart(fight->clocker.clock);
        }
    }
}