/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** keyboard.c
*/

#include "my_rpg.h"
#include "building_pos.h"

sfBool collision_building(town_t *town, sfInt8 side);

void idle(town_t *town)
{
    if (KEY_PRESS(sfKeyS) || KEY_PRESS(sfKeyZ) ||
        KEY_PRESS(sfKeyQ) || KEY_PRESS(sfKeyD)) {
        if (town->player.rect.rect.left > 93)
            town->player.rect.rect.left = 0;
        else
            town->player.rect.rect.left += 47;
    }
    else {
        town->player.rect.rect.left = 47;
    }
    sfSprite_setTextureRect(town->player.sprite, town->player.rect.rect);
}

void movement(town_t *town)
{
    if (KEY_PRESS(sfKeyZ) || KEY_PRESS(sfKeyS)) {
        if (KEY_PRESS(sfKeyZ) && collision_building(town, TOP)) {
            town->player.rect.rect.top = 144;
            town->bg.pos.y += 5;
        }
        else if (KEY_PRESS(sfKeyS) && collision_building(town, BOTTOM)) {
            town->player.rect.rect.top = 0;
            town->bg.pos.y -= 5;
        }
    }else if (KEY_PRESS(sfKeyQ) || KEY_PRESS(sfKeyD)) {
        if (KEY_PRESS(sfKeyQ) && collision_building(town, LEFT)) {
            town->player.rect.rect.top = 48;
            town->bg.pos.x += 5;
        }
        else if (KEY_PRESS(sfKeyD) && collision_building(town, RIGHT)) {
            town->player.rect.rect.top = 96;
            town->bg.pos.x -= 5;
        }
    }
    sfSprite_setPosition(town->bg.sprite, town->bg.pos);
}

void animation_fountain(town_t *town)
{
    if (town->fountain.rect.rect.left > 406)
        town->fountain.rect.rect.left = 0;
    else
        town->fountain.rect.rect.left += 138;
    town->fountain.rect.rect.width = 125;
    sfSprite_setTextureRect(town->fountain.sprite, town->fountain.rect.rect);
}

void my_keyboard(window_t *window, town_t *town, sfEvent *event, sound_t *sound)
{
    if (KEY_PRESS(sfKeyEscape)) {
        event->key.code = sfKeyCount;
        window->status = PAUSE;
        do_pause(window, sound);
    }
    idle(town);
    movement(town);
    animation_fountain(town);
}