/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** my_event.c
*/

#include "my_rpg.h"

void my_event(sfEvent *event, window_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, event))
        if (event->type == sfEvtClosed)
            window->status = END;
}
