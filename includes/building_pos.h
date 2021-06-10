/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-tibo.pendino
** File description:
** building_pos.h
*/

#ifndef _BUILDING_POS_H_
#define _BUILDING_POS_H_

#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef enum {
    TOP = 1,
    BOTTOM,
    LEFT,
    RIGHT
} side_e;


static const sfVector2f pos_church = {.x = 250, .y = 700};

static const sfVector2f pos_hdv = {.x = 1275, .y = 100};

static const sfVector2f pos_fountain = {.x = 1567, .y = 1250};

static const sfUint32  n_h_h = 4;
static const sfVector2f pos_house_h[] = {{.x = 180, .y = 100},
                                            {.x = 2400, .y = 1250},
                                            {.x = 2300, .y = 1850},
                                            {.x = 275, .y = 1725}};

static const sfUint32 n_h_v = 5;
static const sfVector2f pos_house_v[] = {{.x = 2500, .y = 75},
                                            {.x = 300, .y = 2400},
                                            {.x = 1050, .y = 2400},
                                            {.x = 1800, .y = 2400},
                                            {.x = 2700, .y = 2400}};

static const sfVector2f ext_bg_pos[] = {{.x =  -2200, .y = -2540},
                                        {.x =  960, .y = 600}};

static const sfUint32 n_png = 3;
static const sfVector2f pos_pnj[] = {{.x = 1600, .y = 600},
                                        {.x =  675, .y = 1375},
                                        {.x = 1600, .y = 1325}};

static const sfUint32 n_mushroom = 5;
static const sfUint32 n_wine = 5;

static const sfVector2f pos_mushroom[] = {{1000, 1800},
                                        {50, 50},
                                        {2000, 2000},
                                        {50, 1000},
                                        {1000, 500}};

static const sfVector2f pos_wine[] = {{1000, 2800},
                                        {3000, 3000},
                                        {1400, 2000},
                                        {2000, 50},
                                        {3000, 300}};

#endif /* _BUILDING_POS_H_ */