/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** do_inventory.c
*/

#include "my_rpg.h"
#include "myself.h"

void do_myself(myself_t *myself)
{
    if (KEY_PRESS(sfKeyI))
        while (1) {
            if (myself->display == 0 && !KEY_PRESS(sfKeyI)) {
                myself->display = 1;
                break;
            }
            else if (myself->display == 1 && !KEY_PRESS(sfKeyI)) {
                myself->display = 0;
                break;
            }
        }
}