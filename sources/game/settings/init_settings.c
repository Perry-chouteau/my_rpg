/*
** EPITECH PROJECT, 2021
** init_tuto
** File description:
** init_tuto
*/

#include <stdlib.h>
#include "my_rpg.h"

static const char *settings_txt[] = {"How To Play ?",
                                    "Quit",
                                    "Save & Back",
                                    "Volume"};
static const char *settings_view_filepath[] = {
                            "assets/img/settings/settings_background.png",
                            "assets/img/menu/banner.png",
                            "assets/img/menu/banner.png",
                            "assets/img/menu/banner.png",
                            "assets/img/settings/minus_button.png",
                            "assets/img/settings/plus_button.png",
                            "assets/img/settings/sound_button.png",
                            "assets/img/settings/sound_muted_button.png",
                            "assets/img/menu/banner_hover.png",
                            "assets/img/menu/banner_onclick.png"};

static void init_text(settings_t *settings)
{
    sfFont *font = sfFont_createFromFile("assets/font/font.ttf");

    settings->text = malloc(sizeof(sfText *) * 4);
    for (int i = 0; i < 4; i++) {
        settings->text[i] = sfText_create();
        sfText_setFont(settings->text[i], font);
        sfText_setString(settings->text[i], settings_txt[i]);
        sfText_setPosition(settings->text[i], settings_txt_pos[i]);
        sfText_setColor(settings->text[i], sfBlack);
    }
}

int init_settings(settings_t *settings)
{
    settings->view = malloc(sizeof(object_t) * 10);
    for (int i = 0; i < 10; i++) {
        settings->view[i].texture =
        sfTexture_createFromFile(settings_view_filepath[i], NULL);
        settings->view[i].sprite = sfSprite_create();
        sfSprite_setTexture(settings->view[i].sprite, settings->view[i].texture,
                                                                    sfFalse);
        sfSprite_setPosition(settings->view[i].sprite, settings_view_pos[i]);
    }
    init_text(settings);
    settings->over_sound_status = 0;
    return 0;
}

int destroy_settings(settings_t *settings)
{
    for (int i = 0; i < 10; i++) {
        sfSprite_destroy(settings->view[i].sprite);
        sfTexture_destroy(settings->view[i].texture);
    }
    free(settings->view);
    for (int i = 0; i < 4; i++)
        sfText_destroy(settings->text[i]);
    free(settings->text);
    return 0;
}