/*
** EPITECH PROJECT, 2021
** init_conv.c
** File description:
** header for init_conv.c
*/

#include <SFML/Graphics/Font.h>
#include <stdlib.h>
#include "history/history.h"

size_t my_strlenn(char const *str)
{
    size_t i = 0;

    for (; str[i] != '\0'; ++i);
    return (i);
}

size_t len_tab(char **tab)
{
    int i;

    for (i = 0; tab[i] != NULL ; ++i);
    return (i);
}

char **str_to_wordtab(char const *str, char sep)
{
    size_t idx = 0;
    int pos_y = 0;
    size_t str_size = my_strlenn(str);
    char **tab = malloc((str_size + 1) * sizeof(char *));

    if (tab == NULL)
        return (NULL);
    for (int pos_x = 0; idx < str_size; pos_y++, pos_x = 0) {
        tab[pos_y] = malloc((str_size + 1) * sizeof(char));
        if (tab[pos_y] == NULL)
            return (NULL);
        for (; str[idx] == sep && idx < str_size; idx++);
        while (str[idx] != sep && idx < str_size)
            tab[pos_y][pos_x++] = str[idx++];
        tab[pos_y][pos_x] = '\0';
        for (; str[idx] == sep && idx < str_size; idx++);
    }
    tab[pos_y] = NULL;
    tab[str_size] = NULL;
    return (tab);
}

int my_init_text(sfText ***text, int nb_text)
{
    char **pass = str_to_wordtab(all_story[nb_text], '\t');
    size_t tab_len = len_tab(pass);
    sfVector2f pos = {100, 200};
    sfFont *font = sfFont_createFromFile("assets/font/font.ttf");

    text[0] = malloc(sizeof(sfText *) * tab_len);
    for (size_t idx = 0; idx < tab_len; idx++) {
        text[0][idx] = sfText_create();
        sfText_setFont(text[0][idx], font);
        sfText_setString(text[0][idx], pass[idx]);
        sfText_setPosition(text[0][idx], pos);
        sfText_setColor(text[0][idx], sfWhite);
        sfText_setScale(text[0][idx], (sfVector2f){2, 2});
    }
    return ((int)tab_len);
}

void init_conv(hist_t *hist)
{
    sfVector2f scale_bg = {2, 1.5f};
    sfVector2f scale_city = {2, 1.5f};

    init_mayor(hist);
    init_hero(hist);
    hist->city.spt = sfSprite_create();
    hist->city.tex = sfTexture_createFromFile(IMG_CITY, NULL);
    sfSprite_setTexture(hist->city.spt , hist->city.tex, sfTrue);
    sfSprite_scale(hist->city.spt, scale_city);
    hist->start.spt.spt = sfSprite_create();
    hist->start.spt.tex = sfTexture_createFromFile(BG_START, NULL);
    hist->start.clock = sfClock_create();
    sfSprite_setTexture(hist->start.spt.spt , hist->start.spt.tex, sfTrue);
    sfSprite_scale(hist->start.spt.spt, scale_bg);
}