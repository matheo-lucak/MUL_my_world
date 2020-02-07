##
## EPITECH PROJECT, 2019
## Makefile minishell_1
## File description:
## compiles c files with libs into the minishell1 program
##

SRC	=	src/my_world.c							\
		src/initializers/init_window.c			\
		src/initializers/init_world_map.c		\
		src/initializers/init_presets.c			\
		src/math_process/project_iso_point.c	\
		src/math_process/my_radians.c			\
		src/map_assets/create_2d_map.c			\
		src/map_assets/create_line.c			\
		src/map_assets/draw_2d_map.c			\
		src/map_assets/generate_map.c			\
		src/map_assets/control_map_view.c		\
		src/free_resources/free_win_sets.c		\
		src/free_resources/free_world_map.c		\
		src/free_resources/free_array.c



MAIN	=	src/main.c

NAME	=	my_world

CFLAGS	=	-Wall -Wextra -W

CPPFLAGS	=	-I./include/

LDLIBS	=	-lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-network -lm

LDLIBTEST	=	-lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-network -lm -lcriterion

all:	$(NAME)

$(NAME):
	$(CC) -o $@ $(MAIN) $(SRC) $(CPPFLAGS) $(LDLIBS)

debug:
	$(CC) -g -o $@ $(SRC) $(MAIN) $(CPPFLAGS) $(LDLIBS)

tests_run:
	$(CC) -o $@ $(SRC) tests/*.c $(CPPFLAGS) $(LDLIBTEST) --coverage
	./$@
	$(RM) $@

coverage:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

clean:
	$(RM) $(NAME)
	$(RM) debug
	$(RM) tests_run
	$(RM) *.gcda *.gcno
	$(RM) vgcore.*

fclean:	clean

re:	fclean all

.NOTPARALLEL:
.PHONY: all debug tests_run coverage clean fclean re