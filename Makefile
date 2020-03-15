##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rtfm
##

MAIN					=	src/main.c

SRC_FREE_RESOURCES		=	src/free_resources/free_array.c					\
							src/free_resources/free_game_structures.c		\
							src/free_resources/free_resources_fps.c			\
							src/free_resources/free_shaders_array.c			\
							src/free_resources/free_terraformer.c			\
							src/free_resources/free_textures_array.c		\
							src/free_resources/free_win_settings.c			\

SRC_GAME_DRAW_UPDATE	=	src/game_draw_update/draw_fps.c					\
							src/game_draw_update/game_view_update.c			\

SRC_GAME_OBJECT			=	src/game_object/create_game_object.c			\
							src/game_object/draw_game_object.c				\
							src/game_object/get_config_path.c				\
							src/game_object/find_game_object.c				\
							src/game_object/free_game_object.c				\
							src/game_object/init_advanced_component.c		\
							src/game_object/init_basic_component.c			\
							src/game_object/init_component.c				\
							src/game_object/init_game_object_param.c		\
							src/game_object/init_game_object.c				\
							src/game_object/set_advanced_component.c		\
							src/game_object/set_basic_component.c			\
							src/game_object/set_game_object_param.c			\
							src/game_object/add_game_obj_to_list.c			\

SRC_GAME_STATE_HANDLING	=	src/game_state_handling/edit_mode.c				\
							src/game_state_handling/game_state_checker.c	\
							src/game_state_handling/my_world.c				\
							src/game_state_handling/update_window_settings.c\

SRC_INITIALIZERS		=	src/initializers/init_game_structures.c			\
							src/initializers/init_hud.c						\
							src/initializers/init_map_2d.c					\
							src/initializers/init_menu_assets.c				\
							src/initializers/init_resources_fps.c			\
							src/initializers/init_shaders.c					\
							src/initializers/init_terraformer.c				\
							src/initializers/init_textures.c				\
							src/initializers/init_win_settings.c			\

SRC_INPUTS_HANDLING		=	src/inputs_handling/angle_rotation.c			\
							src/inputs_handling/control_view.c				\
							src/inputs_handling/mouse_input.c				\
							src/inputs_handling/translations.c				\

SRC_MAP_GENERATION		=	src/map_generation/apply_biomes.c				\
							src/map_generation/generate_map.c				\
							src/map_generation/get_hash.c					\
							src/map_generation/open_map.c					\
							src/map_generation/perlin_noise.c				\
							src/map_generation/save_map.c					\

SRC_MAP_UPDATE			=	src/map_update/hud/draw_edit_button.c			\
							src/map_update/hud/draw_hud.c					\
							src/map_update/hud/draw_mode_button.c			\
							src/map_update/hud/draw_save_button.c			\
							src/map_update/hud/draw_slider.c				\
							src/map_update/hud/draw_sound_button.c			\
							src/map_update/hud/draw_text_box.c				\
							src/map_update/hud/draw_texture_bar.c			\
							src/map_update/hud/draw_view_mode_button.c		\
							src/map_update/draw_circles.c					\
							src/map_update/draw_tile_map_2d.c				\
							src/map_update/map_update.c						\
							src/map_update/update_view_side.c				\
							src/map_update/update_border.c					\

SRC_MATH_PROCESS		=	src/math_process/get_randnb.c					\
							src/math_process/magnet_number.c				\
							src/math_process/project_iso_point.c			\

SRC_MENU				=	src/menu/hovering_earth_action.c				\
							src/menu/run_menu.c								\

SRC_PIXEL				=	src/pixel/free_pixels.c							\
							src/pixel/pixel_color.c							\
							src/pixel/pixel_physic.c						\
							src/pixel/pixellist_add_pixels.c				\
							src/pixel/pixellist_add_x_pixels.c				\
							src/pixel/update_pixel.c						\

SRC_VECTOR_ENGINE		=	src/vector_engine/vector_engine_compute.c		\
							src/vector_engine/vector_engine_prop.c			\

SRC_OTHER				=	src/usage.c										\
							src/window_actions.c

OBJ					=	$(MAIN:.c=.o) $(SRC_FREE_RESOURCES:.c=.o) $(SRC_GAME_DRAW_UPDATE:.c=.o) $(SRC_GAME_OBJECT:.c=.o) $(SRC_GAME_STATE_HANDLING:.c=.o) $(SRC_INITIALIZERS:.c=.o) $(SRC_INPUTS_HANDLING:.c=.o) $(SRC_MAP_GENERATION:.c=.o) $(SRC_MAP_UPDATE:.c=.o) $(SRC_MATH_PROCESS:.c=.o) $(SRC_MENU:.c=.o) $(SRC_PIXEL:.c=.o) $(SRC_VECTOR_ENGINE:.c=.o) $(SRC_OTHER:.c=.o)

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
						tar -xf assets.tar.xz

debug:					CPPFLAGS += -g
debug:					clean $(LIB) $(OBJ)
						$(CC) -o $@ $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

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
