##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile du my_defender
##

GAME_NAME	=	sources/game

START_NAME	=	$(GAME_NAME)/start
EVENT_NAME	=	$(GAME_NAME)/event
TUTO_NAME	=	$(GAME_NAME)/tutorial
MENU_NAME	=	$(GAME_NAME)/menu
PAUSE_NAME	=	$(GAME_NAME)/pause
TOWN_NAME	=	$(GAME_NAME)/town
MYSELF_NAME	=	$(GAME_NAME)/myself
SETTINGS_NAME	=	$(GAME_NAME)/settings
FIGHT_NAME	=	$(GAME_NAME)/fight
BOSS_NAME	=	$(GAME_NAME)/boss
CONV_NAME	=	$(GAME_NAME)/conv
QUEST_NAME	=	$(GAME_NAME)/quest

INIT_NAME	=	/init
DRAW_NAME	=	/draw
COLLISION_NAME	=	/collision

TOWN	=	$(TOWN_NAME)$(INIT_NAME)/global_init_town.c	\
			$(TOWN_NAME)$(INIT_NAME)/init_bg.c	\
			$(TOWN_NAME)$(INIT_NAME)/init_player.c	\
			$(TOWN_NAME)$(INIT_NAME)/init_mouse.c	\
			$(TOWN_NAME)$(INIT_NAME)/init_building.c	\
			$(TOWN_NAME)$(INIT_NAME)/init_pnj.c	\
			$(TOWN_NAME)$(COLLISION_NAME)/collision_building.c	\
			$(TOWN_NAME)$(COLLISION_NAME)/collision_church.c	\
			$(TOWN_NAME)$(COLLISION_NAME)/collision_hdv.c	\
			$(TOWN_NAME)$(COLLISION_NAME)/collision_house.c	\
			$(TOWN_NAME)$(COLLISION_NAME)/collision_fountain.c	\
			$(TOWN_NAME)$(COLLISION_NAME)/collision_pnj.c	\
			$(TOWN_NAME)$(DRAW_NAME)/draw_town.c	\
			$(TOWN_NAME)$(DRAW_NAME)/draw_building.c	\
			$(TOWN_NAME)$(DRAW_NAME)/draw_pnj.c	\
			$(TOWN_NAME)$(DRAW_NAME)/draw_mouse.c	\
			$(TOWN_NAME)/keyboard.c	\
			$(TOWN_NAME)/do_town.c

QUEST	=	$(QUEST_NAME)/do_quest.c	\
			$(QUEST_NAME)$(INIT_NAME)/init_quest.c	\
			$(QUEST_NAME)$(DRAW_NAME)/draw_quest.c	\

MYSELF	=	$(MYSELF_NAME)$(DRAW_NAME)/draw_myself.c	\
			$(MYSELF_NAME)$(INIT_NAME)/global_init_myself.c	\
			$(MYSELF_NAME)$(INIT_NAME)/init_face.c	\
			$(MYSELF_NAME)$(INIT_NAME)/init_inventory.c	\
			$(MYSELF_NAME)$(INIT_NAME)/init_skill_tree.c	\
			$(MYSELF_NAME)$(INIT_NAME)/init_quest.c	\
			$(MYSELF_NAME)/do_myself.c	\
			$(MYSELF_NAME)/do_skill_tree.c

FIGHT	=		$(FIGHT_NAME)/init_fight.c      \
				$(FIGHT_NAME)/init_lib.c        \
				$(FIGHT_NAME)/my_itoa.c         \
				$(FIGHT_NAME)/do_fight.c        \
				$(FIGHT_NAME)/drawing.c			\
				$(FIGHT_NAME)/events_fight.c	\
				$(FIGHT_NAME)/animation.c		\
				$(FIGHT_NAME)/destroy_fight.c

MENU	=	$(MENU_NAME)/init_menu.c	\
			$(MENU_NAME)/do_menu.c

SETTINGS	=	$(SETTINGS_NAME)/init_settings.c	\
				$(SETTINGS_NAME)/do_settings.c		\
				$(SETTINGS_NAME)/sound_settings.c	\
				$(SETTINGS_NAME)/animation_settings.c	\
				$(SETTINGS_NAME)/input_settings.c

TUTO	=	$(TUTO_NAME)/do_tuto.c	\
			$(TUTO_NAME)/init_tuto.c

PAUSE	=	$(PAUSE_NAME)/init_pause.c	\
			$(PAUSE_NAME)/do_pause.c	\
			$(PAUSE_NAME)/sound_pause.c	\
			$(PAUSE_NAME)/animation_pause.c	\
			$(PAUSE_NAME)/input_pause.c

EVENT	=	$(EVENT_NAME)/my_event.c

START	=	$(START_NAME)$(INIT_NAME)/init_window.c	\
			$(START_NAME)$(INIT_NAME)/init_sound.c	\
			$(START_NAME)/start.c	\
			$(START_NAME)/destroy.c

CONV	=	$(CONV_NAME)/do_conv.c	\
			$(CONV_NAME)/init_conv.c	\
			$(CONV_NAME)/init_png.c		\
			$(CONV_NAME)/destroy_conv.c

SRC	=	$(START)	$(EVENT)	\
		$(TUTO)	$(MENU)	$(SETTINGS)	\
		$(TOWN)	$(MYSELF)	$(QUEST)	$(PAUSE)	\
		$(FIGHT)					\
		$(CONV)

SRC_MAIN	=	sources/main.c

OBJ			=	$(SRC:.c=.o)	\
				$(SRC_MAIN:.c=.o)

CC	=	gcc

CPPFLAGS	=	-iquote ./includes/

CFLAGS		=	-W -Wall -Wextra

LDFLAGS		=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

NAME		=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

debug: CFLAGS+=-g3
debug: re

.PHONY:	all clean fclean re