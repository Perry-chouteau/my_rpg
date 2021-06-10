/*
** EPITECH PROJECT, 2021
** do_tuto
** File description:
** do_tuto
*/

#include "my_rpg.h"

static void draw_pause(window_t *window, pause_t *pause)
{
    sfRenderWindow_clear(window->window, sfBlack);
    for (int i = 0; i < 10; i++)
        sfRenderWindow_drawSprite(window->window, pause->view[i].sprite,
                                                                    NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawText(window->window, pause->text[i], NULL);
    sfRenderWindow_display(window->window);
}

static void change_pause(window_t *window, pause_t *pause,
                            sfEvent *event, sound_t *sound)
{
    my_event(event, window);
    move_pause_banner(window, pause, event, sound);
    move_pause_muted_icon(window, pause, event, sound);
    scale_pause_icons(window, pause, sound, event);
    check_event_volume(sound);
}

int do_pause(window_t *window, sound_t *sound)
{
    pause_t pause;
    sfEvent event;

    if (window->window == NULL || init_pause(window, &pause))
        return (-1);
    while (window->status == PAUSE) {
        change_pause(window, &pause, &event, sound);
        if (check_escape() == 1) {
            if (window->previous_status == TOWN)
                window->status = TOWN;
            destroy_pause(&pause);
            event.key.code = sfKeyCount;
            return 0;
        }
        draw_pause(window, &pause);
    }
    return 0;
}