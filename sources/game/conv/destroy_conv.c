/*
** EPITECH PROJECT, 2021
** destroy_conv.c
** File description:
** header for destroy_conv.c
*/

#include "history/history.h"

void destroy_conv(hist_t *hist)
{
    sfSprite_destroy(hist->start.spt.spt);
    sfSprite_destroy(hist->start.conv.spt);
    sfSprite_destroy(hist->hero.spt.spt);
    sfSprite_destroy(hist->hero.conv.spt);
    sfSprite_destroy(hist->mayor.spt.spt);
    sfSprite_destroy(hist->mayor.conv.spt);

}