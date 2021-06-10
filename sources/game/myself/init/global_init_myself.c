/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** init_myself.c
*/

#include <stdlib.h>
#include "my_rpg.h"

int init_face(object_t * face);

int init_inventory(object_t * inventory);

int init_items(item_t *items);

int init_quest(object_t *quest);

int init_skill_tree(object_t *skill_tree);

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

char *my_revstr(char *str)
{
    char temp;
    int c = my_strlen(str) - 1;
    int d = 0;

    for (; c > d ; d++ ) {
        temp = str[c];
        str[c] = str[d];
        str[d] = temp;
        c--;
    }
    return (str);
}

void my_init_score(myself_t *myself)
{
    size_t tab_len = len_tab(myself->score);
    sfFont *font = sfFont_createFromFile("assets/font/font.ttf");

    myself->nb_score = malloc(sizeof(sfText *) * tab_len);
    for (size_t idx = 0; idx < tab_len; idx++) {
        myself->nb_score[idx] = sfText_create();
        sfText_setFont(myself->nb_score[idx], font);
        sfText_setString(myself->nb_score[idx], myself->score[idx]);
        sfText_setColor(myself->nb_score[idx], sfWhite);
        sfText_setScale(myself->nb_score[idx], (sfVector2f){0.8f, 0.8f});
    }
}

int init_myself(myself_t *myself)
{
    myself->score = malloc(sizeof(char *) * 4);
    myself->items = malloc(sizeof(item_t) * item_max);
    myself->damage = 3;
    myself->life = 100;
    myself->level = 1;
    myself->score[0] = my_itoa(myself->life);
    myself->score[1] = my_itoa(myself->damage);
    myself->score[2] = my_itoa(myself->level);
    myself->score[3] = NULL;
    if (!myself->items)
        return -1;
    my_init_score(myself);
    text_quests(myself);
    if (init_face(&myself->face) ||
            init_inventory(&myself->inventory) ||
            init_items(myself->items) ||
            init_quest(&myself->quest) ||
            init_skill_tree(&myself->skill_tree))
        return -1;
    return 0;
}