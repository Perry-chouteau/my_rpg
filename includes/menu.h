/*
** EPITECH PROJECT, 2021
** forest
** File description:
** forest
*/

#ifndef _MENU_H_
#define _MENU_H_

#include "object.h"

typedef struct menu_s {
    object_t *view;
    sfText **text;
    int over_sound_status;
}menu_t;

typedef enum index_menu {
    BACKGROUND = 0,
    BANNER01,
    BANNER02,
    BANNER03,
    BANNER_HOVER,
    BANNER_ONCLICK
}index_menu_e;

#endif /* _MENU_H_ */
