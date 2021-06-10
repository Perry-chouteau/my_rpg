/*
** EPITECH PROJECT, 2021
** animation_settings
** File description:
** animation_settings
*/

#include "my_rpg.h"

void move_pause_banner(window_t *window, pause_t *pause,
sfEvent *event, sound_t *sound)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window->window);
    for (int i = 0; i < 4; i++) {
        if ((float)mouse_pos.x > settings_view_pos[i].x
        && (float)mouse_pos.x < settings_view_pos[i].x + width_banner
        && (float)mouse_pos.y > settings_view_pos[i].y
        && (float)mouse_pos.y < settings_view_pos[i].y + height_banner) {
            sfSprite_setPosition(pause->view[BANNER_HOVER_].sprite,
            settings_view_pos[i]);
            play_pause_sound_hover(pause, sound);
            pause_bag(&i);
            check_pause_onclick(window, pause, event, sound);
            break;
        } else {
            sfSprite_setPosition(pause->view[BANNER_ONCLICK_].sprite,
            settings_view_pos[9]);
            sfSprite_setPosition(pause->view[BANNER_HOVER_].sprite,
            settings_view_pos[9]);
            pause->over_sound_status = 0;
        }
    }
}

void move_pause_muted_icon(window_t *window, pause_t *pause,
sfEvent *event, sound_t *sound)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window->window);

    if ((float)mouse_pos.x > settings_view_pos[6].x
    && (float)mouse_pos.x < settings_view_pos[6].x + width_icon
    && (float)mouse_pos.y > settings_view_pos[6].y
    && (float)mouse_pos.y < settings_view_pos[6].y + height_icon) {
        sfSprite_setPosition(pause->view[VOL_MUTE].sprite,
        settings_view_pos[6]);
        if (pause->over_sound_status == 0 && sound->mute_status == 0) {
            pause->over_sound_status = 1;
            sfSound_play(sound->hover_sfx);
        }
        check_mute_click(event, sound);
    } else {
        sfSprite_setPosition(pause->view[VOL_MUTE].sprite,
        settings_view_pos[9]);
        pause->over_sound_status = 0;
    }
}

void scale_pause_icons(window_t *window, pause_t *pause,
sound_t *sound, sfEvent *event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window->window);
    for (int i = 4; i < 6; i++) {
        if ((float)mouse_pos.x > settings_view_pos[i].x
        && (float)mouse_pos.x < settings_view_pos[i].x + width_icon
        && (float)mouse_pos.y > settings_view_pos[i].y
        && (float)mouse_pos.y < settings_view_pos[i].y + height_icon) {
            sfSprite_setScale(pause->view[i].sprite,
            (sfVector2f){.x = 1.2, .y = 1.2});
            if (pause->over_sound_status == 0 && sound->mute_status == 0) {
                pause->over_sound_status = 1;
                sfSound_play(sound->hover_sfx);
            }
            if (event->mouseButton.button == sfMouseLeft
            && event->type == sfEvtMouseButtonReleased)
                change_volume(sound, i);
        } else {
            sfSprite_setScale(pause->view[i].sprite, (sfVector2f){1.0, 1.0});
            pause->over_sound_status = 0;
        }
    }
}