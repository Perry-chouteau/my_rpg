/*
** EPITECH PROJECT, 2021
** do_tuto
** File description:
** do_tuto
*/

#include "my_rpg.h"

static void draw_settings(window_t *window, settings_t *settings)
{
    sfRenderWindow_clear(window->window, sfBlack);
    for (int i = 0; i < 10; i++)
        sfRenderWindow_drawSprite(window->window, settings->view[i].sprite,
                                                                    NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawText(window->window, settings->text[i], NULL);
    sfRenderWindow_display(window->window);
}

int do_settings(window_t *window, sound_t *sound)
{
    settings_t settings;
    sfEvent event;

    if (window->window == NULL || init_settings(&settings))
        return (-1);
    while (window->status == SETTINGS) {
        my_event(&event, window);
        move_banner(window, &settings, &event, sound);
        move_muted_icon(window, &settings, &event, sound);
        scale_icons(window, &settings, sound, &event);
        check_event_volume(sound);
        if (check_escape() == 1) {
            destroy_settings(&settings);
            window->status = MENU;
            return 0;
        }
        draw_settings(window, &settings);
    }
    return 0;
}