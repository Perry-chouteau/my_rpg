/*
** EPITECH PROJECT, 2021
** animation
** File description:
** animation
*/

#include "fight/fight.h"
#include "my_rpg.h"

static void draw_anim(window_t *window, sfSprite *sprite)
{
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawSprite(window->window, sprite, NULL);
    sfRenderWindow_display(window->window);
}

static void anim_loop(window_t *window, sfSprite *sprite, sfVector2f scale,
                        sfVector2f position)
{
    sfClock *clock = sfClock_create();
    int i = 0;

    while (i < 20) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 0.02f) {
            scale.x += 0.1;
            scale.y += 0.1;
            position.x -= 90;
            position.y -= 90;
            sfSprite_setScale(sprite, scale);
            sfSprite_setPosition(sprite, position);
            sfClock_restart(clock);
            ++i;
        }
        draw_anim(window, sprite);
    }
}

void animation_fight(window_t *window)
{
    sfImage *image = sfRenderWindow_capture(window->window);
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfVector2f scale = {.x = 1.0, .y = 1.0};
    sfVector2f position = {.x = 0, .y = 0};
    anim_loop(window, sprite, scale, position);
    sfSprite_destroy(sprite);
}

void anim(sfSprite **sprite, sfIntRect *rect, int *x, sfVector2i limit)
{
    if (x[0] >= limit.x)
        x[0] = -limit.y;
    x[0] += limit.y;
    rect->left = x[0];
    sfSprite_setTextureRect(sprite[0], rect[0]);
}