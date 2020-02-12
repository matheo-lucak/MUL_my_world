##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rtfm
##

CC			=	gcc

SRC			=	src/main.c					\
				src/event_edit_game.c		\
				src/event_inf_game.c		\
				src/event_inf_game2.c		\
				src/event_menu_game.c		\
				src/free_all.c				\
				src/game_start.c			\
				src/game.c					\
				src/init_button.c			\
				src/init_edit_obj.c			\
				src/init_env_background.c	\
				src/init_env_frontground.c	\
				src/init_gobj_comp.c		\
				src/init_gobj_comp2.c		\
				src/init_gobj_param.c		\
				src/init_gobj.c				\
				src/init_hud.c				\
				src/init_hud2.c				\
				src/init_map.c				\
				src/init_map2.c				\
				src/init_obj.c				\
				src/init_player.c			\
				src/init_player2.c			\
				src/init_prop.c				\
				src/init_prop2.c			\
				src/manage_edit_obj.c		\
				src/manage_edit_obj2.c		\
				src/manage_entity_damage.c	\
				src/manage_entity_gravity.c	\
				src/manage_entity_jump.c	\
				src/manage_entity.c			\
				src/manage_hud.c			\
				src/manage_lose.c			\
				src/manage_obj.c			\
				src/manage_obj2.c			\
				src/manage_score.c			\
				src/manage_win.c			\
				src/save_map.c				\
				src/save_map_name.c			\
				src/tool_comp.c				\
				src/tool.c

OBJ			=	$(SRC:.c=.o)

NAME		=	my_runner

CPPFLAGS	=	-I./include/

LDFLAGS		=	-L./lib

LDLIBS		=	-lmy -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm

LIB			=	./lib/libmy.a

ASSET		=	music/		\
				sound/		\
				sprite/		\
				font/		\


$(NAME):	 $(LIB) $(OBJ) $(ASSET)
				$(CC) $(OBJ) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

all:	$(NAME)

debug:	clean $(LIB) $(OBJ)
				rm -f $(NAME)
				$(CC) $(SRC) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -W -Wall -Wextra -g

$(LIB):
				make -C ./lib/my/

$(ASSET):
				tar -xzf asset.tar.gz

clean:
				rm -f $(OBJ)
				make clean -C ./lib/my/

fclean: clean
				rm -f $(NAME)
				make fclean -C ./lib/my
				rm -r $(ASSET)

re:	fclean all

.PHONY:	$(NAME) all clean fclean
