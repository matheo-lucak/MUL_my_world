##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rtfm
##

MAIN				=	src/main.c

SRC					=	src/free_resources/free_array.c						\
						src/free_resources/free_game_structures.c			\
						src/free_resources/free_shaders_array.c				\
						src/free_resources/free_resources_fps.c				\
						src/free_resources/free_terraformer.c				\
						src/free_resources/free_textures_array.c			\
						src/free_resources/free_win_settings.c				\
						src/initializers/init_game_structures.c				\
						src/game_object/create_game_object.c				\
						src/game_object/free_game_object.c					\
						src/game_object/init_component.c					\
						src/game_object/init_game_object.c					\
						src/game_object/set_advanced_component.c			\
						src/game_object/set_basic_component.c				\
						src/game_object/set_game_object_param.c				\
						src/initializers/init_map_2d.c						\
						src/initializers/init_menu_assets.c					\
						src/initializers/init_shaders.c						\
						src/initializers/init_resources_fps.c				\
						src/initializers/init_terraformer.c					\
						src/initializers/init_textures.c					\
						src/initializers/init_win_settings.c				\
						src/inputs_handling/control_view.c					\
						src/inputs_handling/mouse_input.c					\
						src/map_generation/generate_map.c					\
						src/map_generation/get_hash.c						\
						src/map_generation/open_map.c						\
						src/map_generation/perlin_noise.c					\
						src/map_generation/save_map.c						\
						src/map_list/create_map_list.c						\
						src/map_update/draw_circles.c						\
						src/map_update/draw_tile_map_2d.c					\
						src/map_update/map_update.c							\
						src/math_process/get_randnb.c						\
						src/math_process/project_iso_point.c				\
						src/math_process/magnet_number.c					\
						src/menu/menu_update.c								\
						src/menu/menu.c										\
						src/pixel/pixel_physic.c							\
						src/pixel/pixellist_add_pixels.c					\
						src/pixel/pixellist_add_x_pixels.c					\
						src/pixel/update_pixel.c							\
						src/vector_engine/vector_engine_compute.c			\
						src/vector_engine/vector_engine_prop.c				\
						src/window_handling/edit_mode.c						\
						src/window_handling/should_stay_opened.c			\
						src/window_handling/update_window_settings.c		\
						src/window_update/window_update.c					\
						src/my_world.c										\
						src/usage.c

OBJ					=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME 				=	my_world

override CFLAGS		+=	-W -Wall -Wextra

override CPPFLAGS	+=	-I./include/

override LDFLAGS	+=	-L./lib/

override LDLIBS		+= 	-lmy -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm

LIB 				=	lib/libmy.a

ASSETS				=	assets

all:					$(NAME)

$(NAME):				$(LIB) $(OBJ) $(ASSETS)
						$(LINK.o) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

$(LIB):
						$(MAKE) -C ./lib/my

$(ASSETS):
						tar -xf assets.tar.gz

debug:					CPPFLAGS += -g
debug:					$(LIB)
						$(CC) -o $@ $(SRC) $(MAIN) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

tests_run:				LDLIBS += -lcriterion --coverage
tests_run:				CFLAGS += --coverage
tests_run:				$(LIB)
						$(CC) -o $@ $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
						./$@
						mv *.gc* tests/
						$(RM) $@

clean:
						$(RM) $(OBJ)
						$(MAKE) -C lib/my clean

fclean:					clean
						$(RM) $(NAME)
						$(RM) $(OBJ)
						$(RM) -r $(ASSETS)
						$(MAKE) -C lib/my fclean

re:			 			fclean all

.NOTPARALLEL:
.PHONY:					debug all clean fclean re tests_run
