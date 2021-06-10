/*
** EPITECH PROJECT, 2021
** animation_settings
** File description:
** animation_settings
*/

#include "my_rpg.h"

int setting_bag(int *i);

void move_banner(window_t *window, settings_t *settings,
sfEvent *event, sound_t *sound)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window->window);
    for (int i = 0; i < 4; i++) {
        if (mouse_pos.x > settings_view_pos[i].x
        && mouse_pos.x < settings_view_pos[i].x + width_banner
        && mouse_pos.y > settings_view_pos[i].y
        && mouse_pos.y < settings_view_pos[i].y + height_banner) {
            sfSprite_setPosition(settings->view[BANNER_HOVER_].sprite,
            settings_view_pos[i]);
            play_sound_hover(settings, sound);
            setting_bag(&i);
            check_onclick(window, settings, event, sound);
            break;
        } else {
            sfSprite_setPosition(settings->view[BANNER_ONCLICK_].sprite,
            settings_view_pos[9]);
            sfSprite_setPosition(settings->view[BANNER_HOVER_].sprite,
            settings_view_pos[9]);
            settings->over_sound_status = 0;
        }
    }
}

void move_muted_icon(window_t *window, settings_t *settings,
sfEvent *event, sound_t *sound)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window->window);

    if (mouse_pos.x > settings_view_pos[6].x
    && mouse_pos.x < settings_view_pos[6].x + width_icon
    && mouse_pos.y > settings_view_pos[6].y
    && mouse_pos.y < settings_view_pos[6].y + height_icon) {
        sfSprite_setPosition(settings->view[VOL_MUTE].sprite,
        settings_view_pos[6]);
        if (settings->over_sound_status == 0 && sound->mute_status == 0) {
            settings->over_sound_status = 1;
            sfSound_play(sound->hover_sfx);
        }
        check_mute_click(event, sound);
    } else {
        sfSprite_setPosition(settings->view[VOL_MUTE].sprite,
        settings_view_pos[9]);
        settings->over_sound_status = 0;
    }
}

void scale_icons(window_t *window, settings_t *settings,
sound_t *sound, sfEvent *event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window->window);
    for (int i = 4; i < 6; i++) {
        if (mouse_pos.x > settings_view_pos[i].x
        && mouse_pos.x < settings_view_pos[i].x + width_icon
        && mouse_pos.y > settings_view_pos[i].y
        && mouse_pos.y < settings_view_pos[i].y + height_icon) {
            sfSprite_setScale(settings->view[i].sprite,
            (sfVector2f){.x = 1.2, .y = 1.2});
            if (settings->over_sound_status == 0 && sound->mute_status == 0) {
                settings->over_sound_status = 1;
                sfSound_play(sound->hover_sfx);
            }
            if (event->mouseButton.button == sfMouseLeft
            && event->type == sfEvtMouseButtonReleased)
                change_volume(sound, i);
        } else {
            sfSprite_setScale(settings->view[i].sprite,
            (sfVector2f){.x = 1.0, .y = 1.0});
            settings->over_sound_status = 0;
        }
    }
}