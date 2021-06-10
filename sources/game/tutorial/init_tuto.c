/*
** EPITECH PROJECT, 2021
** init_tuto
** File description:
** init_tuto
*/

#include "my_rpg.h"

static const char *filepath[] = {"assets/img/tutorial/tutorial_background.jpg",
                                "assets/img/tutorial/tutorial_text.png"};

int init_tuto(tuto_t *tuto)
{
    tuto->tuto_background.texture = sfTexture_createFromFile(filepath[0], NULL);
    tuto->tuto_text.texture = sfTexture_createFromFile(filepath[1], NULL);
    tuto->tuto_background.sprite = sfSprite_create();
    tuto->tuto_text.sprite = sfSprite_create();
    tuto->tuto_text.pos = (sfVector2f){.x = 0, .y = -1080};
    sfSprite_setPosition(tuto->tuto_text.sprite, tuto->tuto_text.pos);
    sfSprite_setTexture(tuto->tuto_background.sprite,
    tuto->tuto_background.texture, sfFalse);
    sfSprite_setTexture(tuto->tuto_text.sprite, tuto->tuto_text.texture,
                                                                sfFalse);
    return 0;
}

int destroy_tuto(tuto_t *tuto)
{
    sfSprite_destroy(tuto->tuto_text.sprite);
    sfSprite_destroy(tuto->tuto_background.sprite);
    sfTexture_destroy(tuto->tuto_text.texture);
    sfTexture_destroy(tuto->tuto_background.texture);
    return 0;
}