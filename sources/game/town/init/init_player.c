/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** init_player.c
*/

#include "town.h"

static const char *player_sprite = "assets/img/pnj/player/player_walk.png";
static const sfVector2f player_pos = {.x = 950, .y = 600};
static const sfVector2f player_scale = {.x = 1.2, .y = 1.2};

int init_player(town_t *town)
{
    town->player.pos = player_pos;
    town->player.scale = player_scale;
    town->player.rect.rect = (sfIntRect){0, 0, 47, 48};
    town->player.sprite = sfSprite_create();
    if (!town->player.sprite)
        return -1;
    town->player.texture = sfTexture_createFromFile(player_sprite, NULL);
    sfSprite_setTexture(town->player.sprite, town->player.texture, sfFalse);
    sfSprite_setPosition(town->player.sprite, town->player.pos);
    sfSprite_setScale(town->player.sprite, town->player.scale);
    return 0;
}