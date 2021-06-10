/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** inventory.h
*/

#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdbool.h>

#include "object.h"

static const char first_quest[] = "To start, pick up all\nmushrooms(5)"
"\nto prevent spread";
static const char sec_quest[] = "Picking up berries to\n prepare and\n"
"become stronger";
static const char thir_quest[] = "Go to fight the boss!!";

static const char thir[] = "Go to fight the\nBOSS!!";

static char const * const all_quest[] = \
{first_quest, sec_quest, thir_quest, thir};

#define RW_DRAW sfRenderWindow_drawSprite

static const sfUint8 item_max = 15;
static const sfUint8 quest_max = 4;

typedef struct item_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfUint8 damage;
    sfUint8 heal;
    sfUint8 usage;
    bool display;
} item_t;

typedef struct myself_s {
    object_t face;
    object_t inventory;
    item_t *items;
    object_t quest;
    sfText **text_quest;
    object_t skill_tree;
    sfText **nb_score;
    char **score;
    int level;
    int life;
    int damage;
    bool display;
} myself_t;

int len(char const * const tab[]);
void text_quests(myself_t *myself);

#endif /* _INVENTORY_H_ */