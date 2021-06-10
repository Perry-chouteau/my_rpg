/*
** EPITECH PROJECT, 2021
** fight
** File description:
** fight
*/

#ifndef _FIGHT_H_
#define _FIGHT_H_

#include <stdbool.h>
#include "utilities.h"
#include "myself.h"

static const char ATTACK_SOUND[] = "assets/sounds/fight/attack.ogg";
static const char HIT_SOUND[] = "assets/sounds/fight/hit.ogg";

static const char PLAYER_IMG[] = "assets/img/fight/punch.png";
static const char ENEMY_IMG[] = "assets/img/fight/fighter.png";
static const char BOSS_IMG[] = "assets/img/fight/boss.png";
static const char BG_IMG[] = "assets/img/fight/basic_bg.png";
static const char BUTTON1[] = "assets/img/fight/big_button1.png";
static const char BUTTON2[] = "assets/img/fight/big_button2.png";
static const char LOSE[] = "assets/img/fight/you_lose.png";
static const char WIN[] = "assets/img/fight/you_win.png";

static const int LUCK = 3;

static const sfVector2f POS_BUTTON1 = {604, 850};
static const sfVector2f POS_BUTTON2 = {1335, 850};

typedef enum {NOTHING, BUT1, BUT2} button_status;
typedef enum {player_turn, enemy_turn, finish} turn_status;

typedef struct character_s {
    model_t model;
    clocker_t clocker;
    sound_eff_t attack;
    sound_eff_t hit;
    text_t hp;
    sfIntRect rect;
    int x;
    int life;
    int damage;
}character_t;

typedef struct button_s {
    model_t model;
    text_t text;
}button_t;

typedef struct fight_s {
    model_t background;
    model_t lose;
    model_t win;
    clocker_t clocker;
    button_t button1;
    button_t button2;
    character_t player;
    character_t enemy;
    turn_status turn;
    text_t master;
    button_status button_status;
    bool restart;
    bool boss;
}fight_t;

bool init_fight(fight_t *fight, myself_t *myself);
void destroy_fight(fight_t *fight);

void setting_origin(model_t *model, float x, float y);
bool create_sprite(model_t *model, char const *path);
bool create_text(text_t *text, char const *msg, unsigned int size);
bool create_sound(sound_eff_t *effect, char const *sound_path);

void anim(sfSprite **sprite, sfIntRect *rect, int *x, sfVector2i limit);

#endif /* _FIGHT_H_ */
