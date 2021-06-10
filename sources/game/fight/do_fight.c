/*
** EPITECH PROJECT, 2021
** do_fight
** File description:
** do_fight
*/

#include "my_rpg.h"

static void player_part(window_t *window, fight_t *fight)
{
    draw_hp(window, &fight->enemy);
    draw_hp(window, &fight->player);
    sfRenderWindow_drawSprite(window->window, fight->button1.model.spr, NULL);
    sfRenderWindow_drawSprite(window->window, fight->button2.model.spr, NULL);
    sfRenderWindow_drawText(window->window, fight->button1.text.text, NULL);
    sfRenderWindow_drawText(window->window, fight->button2.text.text, NULL);
}

static void enemy_part(window_t *window, fight_t *fight)
{
    fight->clocker.time =
            sfClock_getElapsedTime(fight->clocker.clock);

    draw_hp(window, &fight->enemy);
    draw_hp(window, &fight->player);
    sfRenderWindow_drawText(window->window, fight->master.text, NULL);
    if (fight->clocker.time.microseconds >= 2000000) {
        fight->player.life -= fight->enemy.damage;
        fight->turn = player_turn;
        sfClock_restart(fight->clocker.clock);
    }
}

static void print_end(window_t *window, fight_t *fight, sfSprite *sprite)
{
    if (fight->restart)
        sfClock_restart(fight->clocker.clock);
    fight->clocker.time = sfClock_getElapsedTime(fight->clocker.clock);
    fight->turn = finish;
    sfRenderWindow_drawSprite(window->window, sprite, NULL);
    if (fight->clocker.time.microseconds >= 4000000)
        window->status = MENU;
    fight->restart = false;
}

static void whos_turn(window_t *window, fight_t * fight)
{
    if (fight->turn != finish)
        finished(window, fight);
    if (fight->turn == player_turn)
        player_part(window, fight);
    if (fight->turn == enemy_turn)
        enemy_part(window, fight);
    if (fight->player.life <= 0)
        print_end(window, fight, fight->lose.spr);
    if (fight->enemy.life <= 0)
        print_end(window, fight, fight->win.spr);
}

bool do_fight(window_t *window, myself_t *myself)
{
    fight_t fight;

    animation_fight(window);
    sfRenderWindow_setMouseCursorVisible(window->window, 1);
    (window->status == BOSS)?(fight.boss = true):(fight.boss = false);
    if (!init_fight(&fight, myself))
        return (false);
    while (window->status == FIGHT || window->status == BOSS) {
        sfRenderWindow_clear(window->window, sfBlack);
        analyse_events(window, &fight);
        do_myself(myself);
        whos_turn(window, &fight);
        sfRenderWindow_display(window->window);
    }
    destroy_fight(&fight);
    return (true);
}