/*
** EPITECH PROJECT, 2021
** destroy_fight
** File description:
** destroy_fight
*/

#include "fight/fight.h"

void destroy_model(model_t *model)
{
    sfSprite_destroy(model->spr);
    sfTexture_destroy(model->tex);
}

static void destroy_character(character_t *character)
{
    sfSprite_destroy(character->model.spr);
    sfTexture_destroy(character->model.tex);
    sfClock_destroy(character->clocker.clock);
    sfSoundBuffer_destroy(character->attack.buffer);
    sfSound_destroy(character->attack.sound);
    sfSoundBuffer_destroy(character->hit.buffer);
    sfSound_destroy(character->hit.sound);
    sfText_destroy(character->hp.text);
    sfFont_destroy(character->hp.font);
}

static void destroy_button(button_t *button)
{
    destroy_model(&button->model);
    sfText_destroy(button->text.text);
    sfFont_destroy(button->text.font);
}

void destroy_fight(fight_t *fight)
{
    destroy_character(&fight->player);
    destroy_character(&fight->enemy);
    destroy_model(&fight->background);
    destroy_model(&fight->lose);
    destroy_model(&fight->win);
    destroy_button(&fight->button1);
    destroy_button(&fight->button2);
    sfText_destroy(fight->master.text);
    sfFont_destroy(fight->master.font);
    sfClock_destroy(fight->clocker.clock);
    fight->restart = true;
}