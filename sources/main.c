/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main of rpg
*/

#include "my_rpg.h"

static int my_getnbr(char const *str)
{
    int nb = 0;
    int n = 1;
    int i = 0;

    for (; str[i] == '-' || str[i] == '+'; i++)
        if (str[i] == '-')
            n *= -1;
    for (;str[i] != '\0'; i++)
        nb = nb * 10 + str[i] - 48;
    return (nb * n);
}

static int my_strcmp(char const *str_one, char const *str_two)
{
    for (int i = 0; str_one[i] && str_two; ++i)
        if (str_one[i] != str_two[i])
            return (str_one[i] - str_two[i]);
    return 0;
}

static int get_fps(char const *nb)
{
    int fps;

    for (int i = 0; nb[i]; ++i) {
        if (nb[i] > '9' || nb[i] < '0')
            return 0;
    }
    fps = my_getnbr(nb);
    if (fps < 30 || fps > 200)
        return 0;
    return (fps);
}

int main(int ac, char const * const av[], char const * const env[])
{
    if (ac > 3 || env[0] == NULL)
        return (84);
    else if (ac == 3 && !my_strcmp(av[1], "-f"))
        return start(get_fps(av[2]));
    else
        return (start(60));
}