/*
** EPITECH PROJECT, 2021
** init_tuto
** File description:
** init_tuto
*/

//#include "my_rpg.h"
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>
#include <stdlib.h>
#include "pause.h"
#include "settings.h"
#include "my_rpg.h"

static const char *settings_txt[] = {"How To Play ?",
                                    "Quit",
                                    "Save & Back",
                                    "Volume"};

static const char *settings_view_filepath[] = {
                            "assets/img/pause/pause_background.png",
                            "assets/img/menu/banner.png",
                            "assets/img/menu/banner.png",
                            "assets/img/menu/banner.png",
                            "assets/img/settings/minus_button.png",
                            "assets/img/settings/plus_button.png",
                            "assets/img/settings/sound_button.png",
                            "assets/img/settings/sound_muted_button.png",
                            "assets/img/menu/banner_hover.png",
                            "assets/img/menu/banner_onclick.png"};

static void init_text(pause_t *pause)
{
    sfFont *font = sfFont_createFromFile("assets/font/font.ttf");

    pause->text = malloc(sizeof(sfText *) * 4);
    for (int i = 0; i < 4; i++) {
        pause->text[i] = sfText_create();
        sfText_setFont(pause->text[i], font);
        sfText_setString(pause->text[i], settings_txt[i]);
        sfText_setPosition(pause->text[i], settings_txt_pos[i]);
        sfText_setColor(pause->text[i], sfBlack);
    }
}

int init_pause(window_t *window, pause_t *pause)
{
    sfRenderWindow_setMouseCursorVisible(window->window, sfTrue);
    pause->view = malloc(sizeof(object_t) * 10);
    for (int i = 0; i < 10; i++) {
        pause->view[i].texture =
        sfTexture_createFromFile(settings_view_filepath[i], NULL);
        pause->view[i].sprite = sfSprite_create();
        sfSprite_setTexture(pause->view[i].sprite, pause->view[i].texture,
                                                                    sfFalse);
        sfSprite_setPosition(pause->view[i].sprite, settings_view_pos[i]);
    }
    init_text(pause);
    pause->over_sound_status = 0;
    return 0;
}

int destroy_pause(pause_t *pause)
{
    for (int i = 0; i < 10; i++) {
        sfSprite_destroy(pause->view[i].sprite);
        sfTexture_destroy(pause->view[i].texture);
    }
    free(pause->view);
    for (int i = 0; i < 3; i++)
        sfText_destroy(pause->text[i]);
    free(pause->text);
    return 0;
}