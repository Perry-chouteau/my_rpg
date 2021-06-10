/*
** EPITECH PROJECT, 2021
** do_town
** File description:
** do_town
*/

#include "my_rpg.h"

static const sfVector2f view_pos[] = {(sfVector2f){.x = 775, .y = 350},
                                    (sfVector2f){.x = 775, .y = 475},
                                    (sfVector2f){.x = 775, .y = 600},
                                    (sfVector2f){.x = -300, .y = -300},
                                    (sfVector2f){.x = -300, .y = -300}};

static const int status[3] = {CONV, SETTINGS, END};

static int menu_bag(int *i)
{
    static int n = -1;

    if (i)
        n = *i;
    return n;
}

static void check_menu_onclick(window_t *window, menu_t *menu,
sfEvent *event, sound_t *sound)
{
    int i = menu_bag(NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSprite_setPosition(menu->view[BANNER_ONCLICK].sprite, view_pos[i]);
        sfSprite_setPosition(menu->view[BANNER_HOVER].sprite, view_pos[3]);
        if (sound->mute_status == 0)
            sfSound_play(sound->onclick_sfx);
    }
    if (event->mouseButton.button == sfMouseLeft
    && event->type == sfEvtMouseButtonReleased) {
        window->status = status[i];
        sfSprite_setPosition(menu->view[BANNER_ONCLICK].sprite, view_pos[4]);
    }
}

static void move_menu_banner(window_t *window, menu_t *menu,
sfEvent *event, sound_t *sound)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window->window);

    sfRenderWindow_setMouseCursorVisible(window->window, 1);
    for (int i = 0; i < 3; i++) {
        if (mouse_pos.x > view_pos[i].x && mouse_pos.x < view_pos[i].x + \
        width_banner && mouse_pos.y > view_pos[i].y &&
        mouse_pos.y < view_pos[i].y + height_banner) {
            sfSprite_setPosition(menu->view[BANNER_HOVER].sprite, view_pos[i]);
            if (menu->over_sound_status == 0 && sound->mute_status == 0) {
                menu->over_sound_status = 1;
                sfSound_play(sound->hover_sfx);
            }
            menu_bag(&i);
            check_menu_onclick(window, menu, event, sound);
            break;
        } else {
            sfSprite_setPosition(menu->view[BANNER_ONCLICK].sprite, \
            view_pos[4]);
            sfSprite_setPosition(menu->view[BANNER_HOVER].sprite, view_pos[3]);
            menu->over_sound_status = 0;
        }
    }
}

int do_menu(window_t *window, sound_t *sound)
{
    menu_t menu;
    sfEvent event;

    if (window->window == NULL || init_menu(&menu))
        return (-1);
    while (window->status == MENU) {
        my_event(&event, window);
        move_menu_banner(window, &menu, &event, sound);
        sfRenderWindow_clear(window->window, sfBlack);
        for (int i = 0; i < 6; i++)
            sfRenderWindow_drawSprite(window->window, menu.view[i].sprite,
                                                                    NULL);
        for (int i = 0; i < 3; i++)
            sfRenderWindow_drawText(window->window, menu.text[i], NULL);
        sfRenderWindow_display(window->window);
    }
    return (0);
}