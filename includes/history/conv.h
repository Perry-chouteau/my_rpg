/*
** EPITECH PROJECT, 2021
** conv.h
** File description:
** header for conv.c
*/

#ifndef CONV_H
#define CONV_H

typedef enum {
    sysnopsis,
    first,
    second,
    final,
}nb_conv;

static const char IMG_PNJ[] = "assets/img/pnj/master/master_face1.png";
static const char IMG_HERO[] = "assets/img/pnj/player/player_face.png";
static const char BG_START[] = "assets/img/conversation/sky.png";
static const char IMG_CONV[] = "assets/img/conversation/dialogue.png";
static const char IMG_CITY[] = "assets/img/conversation/conv.png";


static const char startt[] = "Once upon a time, \ta village tormented"
" for a few years by the big bad Samael\t and his"
" minions\t his plan being to create\t a deadly "
"virus in the shape of mushrooms\t being the star "
"food of our village\t"
"the mayor discovers the trickery\t and called"
" our hero Perry\0";

static const char first_mayor[] = "Oh Hello perry, how was your trip?\t"
" It went well, I came right after"
" your message\t"
"I contacted you because recently infected "
"mushrooms\nhave invaded the city\t How is"
" this possible?\tAfter the break between Samael "
"and the princess.\nhe decided to"
"destroy our pretty city\nCan you pick the "
"mushrooms "
"and get rid of them\t Yes i "
"did!\0";

static const char first_fight[] = "So you are the famous perry!\tWhat is "
"going on here?\t"
"It is to evict this village "
"is useless\n I will improve this "
"village by destroying it."
"\tI won’t let you do "
"that\nI’m here to stop you\0";

static char const * const all_story[] = {startt, first_mayor, first_fight};

#endif //CONV_H
