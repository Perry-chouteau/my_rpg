/*
** EPITECH PROJECT, 2021
** init_town
** File description:
** init_town
*/

#include <stdlib.h>
#include "my_rpg.h"

static const char *view_filepath[] = {"assets/img/menu/menu_background.png",
                                    "assets/img/menu/banner.png",
                                    "assets/img/menu/banner.png",
                                    "assets/img/menu/banner.png",
                                    "assets/img/menu/banner_hover.png",
                                    "assets/img/menu/banner_onclick.png"};

static const sfVector2f view_pos[] = {(sfVector2f){.x = 0, .y = 0},
                                        (sfVector2f){.x = 775, .y = 350},
                                        (sfVector2f){.x = 775, .y = 475},
                                        (sfVector2f){.x = 775, .y = 600},
                                        (sfVector2f){.x = -300, .y = -300},
                                        (sfVector2f){.x = -300, .y = -300}};

static const char *menu_txt[] = {"Start", "Settings", "Quit"};

static const sfVector2f menu_pos[] = {(sfVector2f){.x = 955, .y = 375},
                                        (sfVector2f){.x = 935, .y = 500},
                                        (sfVector2f){.x = 965, .y = 625}};

static void init_text(menu_t *menu)
{
    sfFont *font = sfFont_createFromFile("assets/font/font.ttf");

    menu->text = malloc(sizeof(sfText *) * 3);
    for (int i = 0; i < 3; i++) {
        menu->text[i] = sfText_create();
        sfText_setFont(menu->text[i], font);
        sfText_setString(menu->text[i], menu_txt[i]);
        sfText_setPosition(menu->text[i], menu_pos[i]);
        sfText_setColor(menu->text[i], sfBlack);
    }
}

int init_menu(menu_t *menu)
{
    menu->view = malloc(sizeof(object_t) * 6);
    for (int i = 0; i < 6; i++) {
        menu->view[i].texture = sfTexture_createFromFile(view_filepath[i],
                                                                    NULL);
        menu->view[i].sprite = sfSprite_create();
        sfSprite_setTexture(menu->view[i].sprite, menu->view[i].texture,
                                                                sfFalse);
        sfSprite_setPosition(menu->view[i].sprite, view_pos[i]);
    }
    init_text(menu);
    menu->over_sound_status = 0;
    return (0);
}

int destroy_menu(menu_t *menu)
{
    for (int i = 0; i < 6; i++) {
        sfSprite_destroy(menu->view[i].sprite);
        sfTexture_destroy(menu->view[i].texture);
    }
    for (int i = 0; i < 3; i++)
        sfText_destroy(menu->text[i]);
    return (0);
}