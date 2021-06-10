/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** init.c
*/

#include "my_rpg.h"

int init_window(window_t *windows, int fps)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    windows->window = sfRenderWindow_create(video_mode, "my_rpg",
                                            sfDefaultStyle, NULL);
    if (!windows->window)
        return (84);
    sfRenderWindow_setFramerateLimit(windows->window, fps);
    windows->status = TUTO;
    windows->previous_status = MENU;
    return (0);
}