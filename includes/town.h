/*
** EPITECH PROJECT, 2021
** town
** File description:
** header for town
*/

#ifndef _TOWN_H_
#define _TOWN_H_

#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#include "object.h"

typedef struct town_s {
    object_t mouse;
    object_t e;
    object_t bg;
    object_t player;
    object_t church;
    object_t hdv;
    object_t fountain;
    object_t *house_v;
    object_t *house_h;
    object_t *pnj;
    object_t *mushroom;
    object_t *wine;
}town_t;

#endif /* _TOWN_H_ */
