/*
** EPITECH PROJECT, 2021
** utilities
** File description:
** utilities
*/

#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <SFML/System/Clock.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>

#define CLICK_PRESS sfEvtMouseButtonPressed
#define CLICK_RELEASED sfEvtMouseButtonReleased
#define VECTOR2F(x, y) (sfVector2f){x, y}
#define VECTOR2I(x, y) (sfVector2i){x, y}
#define microsecond(second) (int)(second * 1000000)

typedef struct model_s {
    sfTexture *tex;
    sfSprite *spr;
}model_t;

typedef struct clocker_s {
    sfClock *clock;
    sfTime time;
}clocker_t;

typedef struct sound_eff_s {
    sfSoundBuffer *buffer;
    sfSound *sound;
    bool play;
}sound_eff_t;

typedef struct text_s{
    sfFont *font;
    sfText *text;
}text_t;

#endif /* _UTILITIES_H_ */
