/*
** EPITECH PROJECT, 2021
** do_conv.c
** File description:
** header for do_conv.c
*/

#include "my_rpg.h"
#include <stdio.h>

int do_syn(window_t *window, hist_t *hist)
{
    float sec = sfTime_asSeconds(sfClock_getElapsedTime(hist->start.clock));

    sfText_setColor(hist->start.text.text[0], sfBlack);
    sfText_setPosition(hist->start.text.text[0], (sfVector2f) {100, 100});
    sfRenderWindow_drawText(window->window, hist->start.text.text[0], NULL);
    for (int i = 1; (i * 2) <= 14; ++i) {
        if (sec > (float) (i * 2)) {
            sfText_setColor(hist->start.text.text[i], sfBlack);
            sfText_setPosition(hist->start.text.text[i], (sfVector2f)
                    {100 + (float) (25 * i), 100 + (float) (100 * i)});
            sfRenderWindow_drawText(window->window, hist->start.text.text[i],
                                    NULL);
        }
    }
    while (sfKeyboard_isKeyPressed(sfKeyEnter))
        if (sec > 16 || !sfKeyboard_isKeyPressed(sfKeyEnter))
            return (1);
    sfRenderWindow_display(window->window);
    return (0);
}

int check_time(window_t *window, pnj_t *pnj, pnj_t *hero, int idx)
{
    float sec = sfTime_asSeconds(sfClock_getElapsedTime(pnj->clock));
    static sfVector2f pos = {300, 800};

    if ((sec > 0.3 && idx % 2 == 0) ) {
        sfRenderWindow_drawSprite(window->window, pnj->spt.spt, NULL);
        sfText_setPosition(pnj->text.text[idx], pos);
        sfRenderWindow_drawText(window->window, pnj->text.text[idx], NULL);
    } else if (sec > 0.3 && idx % 2 == 1) {
        sfRenderWindow_drawSprite(window->window, hero->spt.spt, NULL);
        sfText_setPosition(pnj->text.text[idx], pos);
        sfRenderWindow_drawText(window->window, pnj->text.text[idx], NULL);
    }
    if (sec > 8) {
        sfClock_restart(pnj->clock);
        idx++;
    }
    return (idx);
}

int do_all_conv(window_t *window, pnj_t *pnj, pnj_t *hero, nb_conv nb)
{
    static int idx = 0;
    int tab = len(all_story);

    my_init_text(&pnj->text.text, nb);
    sfRenderWindow_drawSprite(window->window, pnj->conv.spt, NULL);
    idx = check_time(window, pnj, hero, idx);
    if (idx > tab || sfKeyboard_isKeyPressed(sfKeyEnter)) {
        window->status = TOWN;
        nb = nb + 1;
        return (nb);
    }
    sfRenderWindow_display(window->window);
    return (nb);
}

static int check_nb_conv(window_t *window, hist_t *hist, int nb_conv)
{
    if (nb_conv == 1) {
        sfRenderWindow_drawSprite(window->window, hist->city.spt, NULL);
        do_all_conv(window, &hist->mayor, &hist->hero, 1);
    }
    return (nb_conv);
}

int do_conv(window_t *window)
{
    hist_t histo;
    sfEvent event;
    static int nb_conv = 0;

    if (window->window == NULL)
        return (- 1);
    init_conv(&histo);
    while (window->status == CONV) {
        my_event(&event, window);
        if (nb_conv == 0) {
            my_init_text(&histo.start.text.text, 0);
            sfRenderWindow_drawSprite(window->window, histo.start.spt.spt,
            NULL);
            nb_conv = do_syn(window, &histo);
        } else
            nb_conv = check_nb_conv(window, &histo, nb_conv);
    }
    return (0);
}