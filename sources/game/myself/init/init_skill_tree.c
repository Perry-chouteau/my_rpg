/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** init_skill_tree.c
*/

#include "myself.h"

static const char *path_skilltree = "assets/img/myself/skill_tree.png";

int init_skill_tree(object_t *skill_tree)
{
    skill_tree->sprite = sfSprite_create();
    if (!skill_tree->sprite)
        return -1;
    skill_tree->texture = sfTexture_createFromFile(path_skilltree, NULL);
    if (!skill_tree->texture)
        return -1;
    skill_tree->pos = (sfVector2f){550, 100};
    skill_tree->scale = (sfVector2f){2, 2};
    sfSprite_setTexture(skill_tree->sprite, skill_tree->texture, 0);
    sfSprite_setPosition(skill_tree->sprite, skill_tree->pos);
    sfSprite_setScale(skill_tree->sprite, skill_tree->scale);
    return 0;
}