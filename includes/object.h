/*
** EPITECH PROJECT, 2021
** object
** File description:
** object
*/

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>

typedef struct
{
    sfIntRect rect;
    int offset;
    int offset_;
    int max;
    int max_;
}rect_t;

typedef struct object_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    rect_t rect;
}object_t;

#endif /* _OBJECT_H_ */
