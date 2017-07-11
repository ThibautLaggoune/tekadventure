##
## Makefile for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure/source_files
## 
## Made by Corentin LEROY
## Login   <corentin.leroy@epitech.eu@epitech.net>
## 
## Started on  Tue Mar 28 16:35:21 2017 Corentin LEROY
## Last update Mon May 29 01:05:53 2017 thibaut
##

CC	=	gcc

SRC	=	change_map.c		\
		edit.c				\
		edit_move_area.c		\
		event.c				\
		event_play.c			\
		event_sprites.c			\
		event_world.c			\
		fill_map.c			\
		fill_map_struct_areas.c		\
		fill_map_struct_chara.c		\
		fill_map_struct_pictures.c	\
		fill_map_struct_sound.c		\
		fill_worldmap.c			\
		fill_world_pictures.c		\
		free.c				\
		function_pointers.c		\
		getfiles.c			\
		get_worldmap.c			\
		loading.c			\
		main.c				\
		main_menu.c			\
		move_background.c		\
		edit_move_area2.c		\
		move_character.c		\
		move_subsprite.c		\
		music.c				\
		nodes.c				\
		npc.c				\
		open_window.c			\
		save_in_file.c			\
		move_icone_io.c			\
		options.c			\
		parallax.c			\
		parse_file.c			\
		parse_map.c			\
		print_draw_rect_ma.c		\
		pick_drop.c			\
		picture_size.c			\
		play.c				\
		play_map.c			\
		play_worldmap.c			\
		quitmenu.c			\
		rectangle.c			\
		sprites.c			\
		subedit.c			\
		text.c				\
		unparse.c			\
		vector.c			\
		volumes.c			\
		world_character.c

OBJ	=	$(SRC:.c=.o)

LFLAGS	=	-lc_graph_prog_full -L../lib -lprintf -lmy

CFLAGS	+=	-I../include/ -W -Wall -Wextra

NAME	=	tekadventure

RM	=	rm -f

$(NAME):	$(OBJ)
	$(CC) -o ../$(NAME) $(OBJ) $(LFLAGS)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) ../$(NAME)

re:	fclean all
