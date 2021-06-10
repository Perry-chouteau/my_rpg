/*
** EPITECH PROJECT, 2021
** history.h
** File description:
** header for history.c
*/

#ifndef HISTORY_H
#define HISTORY_H

#include <SFML/System/Clock.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include "conv.h"

typedef struct sprite_s {
    sfSprite *spt;
    sfTexture *tex;
}sprite_t;

typedef struct textes_s
{
    sfText **text;
    sfClock *clock;
}textes_t;

typedef struct pnj_s
{
    sprite_t spt;
    sprite_t conv;
    sfClock *clock;
    textes_t text;
}pnj_t;

typedef struct hist_s {
    sprite_t city;
    pnj_t mayor;
    pnj_t bg;
    pnj_t start;
    pnj_t hero;
}hist_t;

void init_conv(hist_t *hist);
size_t len_tab(char **tab);
void init_mayor(hist_t *hist);
void init_hero(hist_t *hist);

#endif //HISTORY_H
