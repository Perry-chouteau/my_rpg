/*
** EPITECH PROJECT, 2021
** init_fight
** File description:
** init_fight
*/

#include "fight/fight.h"

static bool init_character(character_t *character, char const *spr_path,
                            myself_t * myself)
{
    if (!create_sprite(&character->model, spr_path))
        return (false);
    setting_origin(&character->model, 0, 2);
    character->clocker.clock = sfClock_create();
    character->attack.play = false;
    if (!create_sound(&character->attack, ATTACK_SOUND))
        return (false);
    if (!character->clocker.clock || !create_sound(&character->hit, HIT_SOUND))
        return (false);
    if (!create_text(&character->hp, "HP", 50))
        return (false);
    sfText_setColor(character->hp.text, sfBlack);
    character->life = myself->life;
    character->damage = myself->damage;
    character->x = 0;
    return (true);
}

static bool init_button(button_t *button, char const *path, sfVector2f pos,
                        char const *msg)
{
    if (!create_sprite(&button->model, path))
        return (false);
    setting_origin(&button->model, 2, 2);
    sfSprite_setPosition(button->model.spr, pos);
    if (!create_text(&button->text, msg, 50))
        return (false);
    sfText_setPosition(button->text.text, VECTOR2F(pos.x - 150, pos.y - 35));
    sfText_setColor(button->text.text, sfBlack);
    return (true);
}

static void set_position(fight_t *fight)
{
    sfSprite_setPosition(fight->player.model.spr, VECTOR2F(320, 550));
    sfSprite_setPosition(fight->enemy.model.spr, VECTOR2F(1420, 260));
    sfText_setPosition(fight->enemy.hp.text, VECTOR2F(570, 160));
    sfText_setPosition(fight->player.hp.text, VECTOR2F(1525, 560));
    sfText_setPosition(fight->master.text, VECTOR2F(775, 770));
}

static bool init_fight2(fight_t *fight)
{
    if (!init_button(&fight->button1, BUTTON1, POS_BUTTON1, "Simple Attack"))
        return (false);
    if (!init_button(&fight->button2, BUTTON2, POS_BUTTON2, "Super Attack"))
        return (false);
    if (!create_text(&fight->master, "Enemy Turn", 70))
        return (false);
    fight->clocker.clock = sfClock_create();
    fight->turn = player_turn;
    fight->restart = true;
    fight->player.rect = (sfIntRect) {0, 0, 396, 366};
    sfSprite_setTextureRect(fight->player.model.spr, fight->player.rect);
    fight->enemy.rect = (sfIntRect) {0, 0, 126, 126};
    sfSprite_setTextureRect(fight->enemy.model.spr, fight->enemy.rect);
    fight->button_status = NOTHING;
    set_position(fight);
    return (true);
}

bool init_fight(fight_t *fight, myself_t *myself)
{
    if (!create_sprite(&fight->background, BG_IMG))
        return (false);
    if (!create_sprite(&fight->win, WIN) || !create_sprite(&fight->lose, LOSE))
        return (false);
    sfSprite_scale(fight->background.spr, VECTOR2F(1, 0.95f));
    if (!init_character(&fight->player, PLAYER_IMG, myself))
        return (false);
    if (!init_character(&fight->enemy,
                        (fight->boss)?(BOSS_IMG):(ENEMY_IMG), myself))
        return (false);
    if (fight->boss) {
        fight->enemy.life += (int)(myself->life * 0.5);
        fight->enemy.damage -= (int)(myself->damage * 0.1);
    } else {
        fight->enemy.life += (int)(myself->life * 0.25);
        fight->enemy.damage -= (int)(myself->damage * 0.2);
    }
    if (!init_fight2(fight))
        return (false);
    return (true);
}