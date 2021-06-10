/*
** EPITECH PROJECT, 2021
** do_town
** File description:
** do_town
*/

#include "my_rpg.h"
#include "myself.h"

static const sfVector3f clear = {(sfInt8)0, (sfInt8)127, (sfInt8)80};

int draw_town(window_t *window, town_t *town, myself_t *myself);

void my_keyboard(window_t *window, town_t *town, sfEvent *event,
                sound_t *sound);

void do_skill(window_t *window, myself_t *myself, sfEvent *event);

void my_clock(void)
{
    sfClock *clock = sfClock_create();

    while (25 > sfTime_asMilliseconds(sfClock_getElapsedTime(clock)));
    sfClock_destroy(clock);
}

int do_town(window_t *window, myself_t *myself, sound_t *sound)
{
    town_t town;
    sfEvent event;

    if (window->window == NULL || init_town(&town))
        return (-1);
    for (; window->status == TOWN; my_clock()) {
        my_keyboard(window, &town, &event, sound);
        my_event(&event, window);
        do_skill(window, myself, &event);
        draw_town(window, &town, myself);
        do_myself(myself);
        sfRenderWindow_display(window->window);
        sfRenderWindow_clear(window->window, \
        sfColor_fromRGB((sfInt8)clear.x, (sfInt8)clear.y, (sfInt8)clear.z));
    }
    return (0);
}