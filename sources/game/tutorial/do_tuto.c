/*
** EPITECH PROJECT, 2021
** do_tuto
** File description:
** do_tuto
*/

#include "my_rpg.h"

static int check_enter(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter))
        return 1;
    return 0;
}
static int animate_text(tuto_t *tuto, sfClock *clock)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.01f
    && tuto->tuto_text.pos.y < -45) {
        tuto->tuto_text.pos.y += 2;
        sfSprite_setPosition(tuto->tuto_text.sprite, tuto->tuto_text.pos);
    }
    return 0;
}

static int draw_tuto(window_t *window, tuto_t *tuto)
{
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawSprite(window->window, tuto->tuto_background.sprite,
                                                                    NULL);
    sfRenderWindow_drawSprite(window->window, tuto->tuto_text.sprite, NULL);
    sfRenderWindow_display(window->window);
    return 0;
}

int do_tuto(window_t *window)
{
    tuto_t tuto;
    sfEvent event;
    sfClock *clock = sfClock_create();

    if (window->window == NULL || init_tuto(&tuto))
        return (-1);
    while (window->status == TUTO) {
        my_event(&event, window);
        animate_text(&tuto, clock);
        if (check_enter() == 1) {
            destroy_tuto(&tuto);
            if (window->previous_status == PAUSE)
                window->status = PAUSE;
            else
                window->status = MENU;
            return 0;
        }
        draw_tuto(window, &tuto);
    }
    return 0;
}