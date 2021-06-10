/*
** EPITECH PROJECT, 2021
** pause
** File description:
** pause
*/

#ifndef PAUSE_H
#define PAUSE_H

#include "object.h"

typedef struct pause_s {
    object_t *view;
    sfText **text;
    int over_sound_status;
}pause_t;

#endif /* PAUSE_H */
