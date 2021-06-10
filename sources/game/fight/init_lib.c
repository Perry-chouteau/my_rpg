/*
** EPITECH PROJECT, 2021
** init_lib
** File description:
** init_lib
*/

#include "fight/fight.h"

bool create_sound(sound_eff_t *effect, char const *sound_path)
{
    effect->buffer = sfSoundBuffer_createFromFile(sound_path);
    effect->sound = sfSound_create();

    if (!effect->buffer || !effect->sound)
        return (false);
    sfSound_setBuffer(effect->sound, effect->buffer);
    return (true);
}

bool create_text(text_t *text, char const *msg, unsigned int size)
{
    text->font = sfFont_createFromFile("assets/font/font.ttf");
    text->text = sfText_create();

    if (!text->font || !text->text)
        return (false);
    sfText_setFont(text->text, text->font);
    sfText_setString(text->text, msg);
    sfText_setCharacterSize(text->text, size);
    return (true);
}

bool create_sprite(model_t *model, char const *path)
{
    model->tex = sfTexture_createFromFile(path, NULL);
    model->spr = sfSprite_create();

    if (!model->spr || !model->tex)
        return (false);
    sfSprite_setTexture(model->spr, model->tex, sfTrue);
    return (true);
}

void setting_origin(model_t *model, float x, float y)
{
    sfVector2f vec;

    if (x == 0 && y != 0) {
        vec.x = 0;
        vec.y = (float) sfTexture_getSize(model->tex).y / y;
    } else if (x != 0 && y == 0) {
        vec.x = (float) sfTexture_getSize(model->tex).x / x;
        vec.y = 0;
    } else {
        vec.x = (float) sfTexture_getSize(model->tex).x / x;
        vec.y = (float) sfTexture_getSize(model->tex).y / y;
    }
    sfSprite_setOrigin(model->spr, vec);
}