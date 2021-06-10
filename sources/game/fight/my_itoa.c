/*
** EPITECH PROJECT, 2021
** my_itoa
** File description:
** my_itoa
*/

#include <stdlib.h>

static int nbr_len(int nbr)
{
    int i = 0;

    if (nbr < 0)
        nbr *= -1;
    for (; nbr > 9; i += 1)
        nbr /= 10;
    return (i + 1);
}

char *my_itoa(int nbr)
{
    int size_nbr = nbr_len(nbr);
    char *str = malloc(sizeof(char) * (size_nbr + 1));

    for (int i = size_nbr - 1; i >= 0; i -= 1, nbr /= 10)
        str[i] = (char)(nbr % 10 + '0');
    str[size_nbr] = '\0';
    return (str);
}