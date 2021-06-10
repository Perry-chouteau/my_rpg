/*
** EPITECH PROJECT, 2021
** init_mayor.c
** File description:
** header for init_mayor.c
*/

#include "history/history.h"

int len(char const * const tab[])
{
    int i;

    for (i = 0; tab[i] != NULL ; ++i);
    return (i);
}

void init_mayor(hist_t *hist)
{
    static sfVector2f pos_d = {- 10, 650};
    sfVector2f scale_pnj = {2.5f, 2.5f};

    hist->mayor.spt.spt = sfSprite_create();
    hist->mayor.conv.spt = sfSprite_create();
    hist->mayor.spt.tex = sfTexture_createFromFile(IMG_PNJ, NULL);
    hist->mayor.conv.tex = sfTexture_createFromFile(IMG_CONV, NULL);
    hist->mayor.clock = sfClock_create();
    sfSprite_setTexture(hist->mayor.conv.spt, hist->mayor.conv.tex, sfTrue);
    sfSprite_setTexture(hist->mayor.spt.spt, hist->mayor.spt.tex, sfTrue);
    sfSprite_scale(hist->mayor.conv.spt, (sfVector2f) {2.33f, 1.7f});
    sfSprite_setPosition(hist->mayor.conv.spt, pos_d);
    sfSprite_setPosition(hist->mayor.spt.spt, (sfVector2f) {150, 300});
    sfSprite_scale(hist->mayor.spt.spt, scale_pnj);
}

void init_hero(hist_t *hist)
{
    sfVector2f scale_pnj = {2.5f, 2.5f};

    hist->hero.spt.spt = sfSprite_create();
    hist->hero.spt.tex = sfTexture_createFromFile(IMG_HERO, NULL);
    sfSprite_setTexture(hist->hero.spt.spt , hist->hero.spt.tex, sfTrue);
    sfSprite_scale(hist->hero.spt.spt, scale_pnj);
    sfSprite_setPosition(hist->hero.spt.spt, (sfVector2f) {1500, 300});
}