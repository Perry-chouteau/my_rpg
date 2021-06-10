/*
** EPITECH PROJECT, 2021
** forest
** File description:
** forest
*/

#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include "object.h"

static const float height_banner = 109;
static const float width_banner = 423;
static const float height_icon = 69;
static const float width_icon = 70;

static const sfVector2f settings_view_pos[] = {(sfVector2f){.x = 0, .y = 0},
                                    (sfVector2f){.x = 435, .y = 345},
                                    (sfVector2f){.x = 435, .y = 800},
                                    (sfVector2f){.x = 1085, .y = 800},
                                    (sfVector2f){.x = 835, .y = 550},
                                    (sfVector2f){.x = 1035, .y = 550},
                                    (sfVector2f){.x = 935, .y = 550},
                                    (sfVector2f){.x = -300, .y = -300},
                                    (sfVector2f){.x = -300, .y = -300},
                                    (sfVector2f){.x = -300, .y = -300}};

static const sfVector2f settings_txt_pos[] = {(sfVector2f){.x = 530, .y = 375},
                                            (sfVector2f){.x = 605, .y = 830},
                                            (sfVector2f){.x = 1235, .y = 830},
                                            (sfVector2f){.x = 915, .y = 500}};

typedef struct settings_s {
    object_t *view;
    sfText **text;
    int over_sound_status;
}settings_t;

typedef enum index_settings {
    BG = 0,
    BANNER_01,
    BANNER_02,
    BANNER_03,
    VOL_MINUS,
    VOL_PLUS,
    VOL_UNMUTE,
    VOL_MUTE,
    BANNER_HOVER_,
    BANNER_ONCLICK_
}index_settings_e;

#endif /* SETTINGS_H_ */
