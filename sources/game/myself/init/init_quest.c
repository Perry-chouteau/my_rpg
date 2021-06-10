/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** init_quest.c
*/

#include "myself.h"
#include <stdlib.h>

static const char path_quest[] = {"assets/img/myself/banner_quest.png"};

static const sfVector2f pos_quest = {1400, 150};

void text_quests(myself_t *myself)
{
    sfFont *font = sfFont_createFromFile("assets/font/font.ttf");

    myself->text_quest = malloc(sizeof(sfText *) * (quest_max + 1));
    myself->text_quest[quest_max] = NULL;
    for (int idx = 0; idx < quest_max; idx++) {
        myself->text_quest[idx] = sfText_create();
        sfText_setFont(myself->text_quest[idx], font);
        sfText_setString(myself->text_quest[idx], all_quest[idx]);
        sfText_setColor(myself->text_quest[idx], sfWhite);
        sfText_setScale(myself->text_quest[idx], (sfVector2f){0.8f, 0.8f});
        sfText_setPosition(myself->text_quest[idx], (sfVector2f){1450, 220});
    }
}

int init_quest(object_t *quest)
{
    quest->sprite = sfSprite_create();

    if (!quest->sprite)
        return -1;
    quest->texture = sfTexture_createFromFile(path_quest, NULL);
    if (!quest->texture)
        return -1;
    quest->pos = pos_quest;
    quest->scale = (sfVector2f) {1.5f, 2};
    sfSprite_setTexture(quest->sprite, quest->texture, 0);
    sfSprite_setPosition(quest->sprite, quest->pos);
    sfSprite_setScale(quest->sprite, quest->scale);
    return 0;
}