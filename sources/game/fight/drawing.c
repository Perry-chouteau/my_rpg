/*
** EPITECH PROJECT, 2021
** drawing
** File description:
** drawing
*/

#include <stdlib.h>
#include "my_rpg.h"

static void draw(window_t *window, fight_t *fight)
{
    sfRenderWindow_drawSprite(window->window, fight->background.spr, NULL);
    sfRenderWindow_drawSprite(window->window, fight->player.model.spr, NULL);
    sfRenderWindow_drawSprite(window->window, fight->enemy.model.spr, NULL);
}

void finished(window_t *window, fight_t *fight)
{
    fight->player.clocker.time =
            sfClock_getElapsedTime(fight->player.clocker.clock);

    if (fight->player.attack.play) {
        sfSound_play(fight->player.attack.sound);
        sfSound_play(fight->enemy.hit.sound);
        fight->player.attack.play = false;
    }
    if (fight->player.clocker.time.microseconds >= microsecond(0.06)) {
        anim(&fight->enemy.model.spr, &fight->enemy.rect,
            &fight->enemy.x, VECTOR2I(882, 126));
        if (fight->button_status == BUT1 || fight->button_status == BUT2)
            anim(&fight->player.model.spr, &fight->player.rect,
                &fight->player.x, VECTOR2I(3168, 396));
        if (fight->player.rect.left == 0)
            fight->button_status = NOTHING;
        sfClock_restart(fight->player.clocker.clock);
    }
    draw(window, fight);
}

void draw_hp(window_t *window, character_t *character)
{
    char *str = my_itoa(character->life);

    sfText_setString(character->hp.text, str);
    sfRenderWindow_drawText(window->window, character->hp.text, NULL);
    free(str);
}