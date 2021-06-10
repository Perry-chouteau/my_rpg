/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** init_face.c
*/

#include "myself.h"

static const char *path_player_face = "assets/img/myself/player_face_ath.png";

int init_face(object_t *face)
{
    face->sprite = sfSprite_create();
    if (!face->sprite)
        return -1;
    face->texture = sfTexture_createFromFile(path_player_face, NULL);
    if (!face->texture)
        return -1;
    face->pos = (sfVector2f){100, 100};
    face->scale = (sfVector2f){2, 2};
    sfSprite_setTexture(face->sprite, face->texture, 0);
    sfSprite_setPosition(face->sprite, face->pos);
    sfSprite_setScale(face->sprite, face->scale);
    return 0;
}