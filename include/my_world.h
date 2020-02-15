/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** my_world.h
*/

#ifndef MY_WORLD_H_

#define MY_WORLD_H_

#include <SFML/System.h>
#include <SFML/Graphics.h>

//An enum of each possible material a square can be.

typedef enum tile_matter_e {
    GRASS,
    STONE,
    GRAVEL,
    SAND,
    WATER,
    SNOW
} tile_matter_t;



//Settings that are helpful for the map rendering and angles of sight.
//
//Can be altered by the player.

typedef struct presets_s {
    unsigned int map_x;
    unsigned int map_y;
    int angle_x;
    int angle_y;
    sfVector2i rotation_speed;
    sfVector2i movement_speed;
} presets_t;



//A square of the map node -> when linked together -> squares of the map
//linked list.

typedef struct map_linked_list_s {
    sfVertexArray *shape_drawer;
    sfRenderStates rstate;
    tile_matter_t matter_state;
    struct map_linked_list_s *next;
    struct map_linked_list_s *prev;
} map_linked_list_t;



//A tile of the map

typedef struct tile_s {
    sfVertexArray *shape_drawer;
    sfRenderStates rstate;
    tile_matter_t matter_state;
} tile_t;



//The alterer of coordinates of the points in the map.

typedef struct map_formatter_s {
    presets_t map_settings;
    float **map_3d;
    sfVector2f **map_2d;
    sfVertexArray ***v_map_2d;
    sfShader **shaders;
    sfTexture **textures;
} map_formatter_t;




//The window tool box.

typedef struct win_settings_s {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfView *view;
} win_settings_t;


/*
** *********
** | Usage |
** *********
*/

//Prints the usage of my_world onto the stdout.
void usage(void);


/*
**                             ****************
**                             | Initializers |
**                             ****************
*/

//Initializes an array to every different sfShader's.
//
//The array is NULL-terminated.
//
//If an error occurs -> returns NULL.
sfShader **init_shaders(void);

//Initializes an array to every different sfTexture's.
//
//The array is NULL-terminated.
//
//If an error occurs -> returns NULL.
sfTexture **init_textures(void);

//Initializes the win_settings structure.
//
//Returns sfTrue (1) if mallocs work.
//Returns sfFalse (0) otherwise.
sfBool init_win_settings(win_settings_t *win_settings);

//Initializes the terraformer structure.
//
//Returns sfTrue (1) if mallocs work.
//Returns sfFalse (0) otherwise.
sfBool init_terraformer(map_formatter_t *terraformer, size_t seed);

//Initializes the win_settings struct, terraformer struct and my_map linked_list.
//
//Returns sfTrue (1) if mallocs work.
//Returns sfFalse (0) otherwise.
sfBool init_game_structures(win_settings_t *win_settings,
                                map_formatter_t *terraformer,
                                map_linked_list_t **my_map);

/*
** ******************
** | Main game loop |
** ******************
*/

//Checks if a window should stay opened or not.
//
//Returns sfTrue (1) if it should.
//Returns sfFalse (0) otherwise.
sfBool should_stay_opened(sfRenderWindow *window);

//Main instance of the my_world edit game.
void my_world(void);


/*
**                            *******************
**                            | Map Linked List |
**                            *******************
*/

//Allocates each map_linked_list_t node and links nodes in the list.
void create_map_list(map_linked_list_t **head,
                    const sfVector2i map_limits,
                    const sfTexture **textures,
                    const sfShader **shaders);

/*
** ************
** | Free'ers |
** ************
*/

//Free's allocated memory for a NULL-terminated texture array.
//If the pointer points to NULL, nothing happens.
void free_textures_array(sfTexture **textures);

//Free's allocated memory for a NULL-terminated shader array.
//If the pointer points to NULL, nothing happens.
void free_shaders_array(sfShader **shaders);

//Free's allocated memory for win_settings.
void free_win_settings(win_settings_t *win_settings);

//Free's allocated memory for terraformer.
//If the pointer points to NULL, nothing happens.
void free_terraformer(map_formatter_t *terraformer);

//Free's allocated memory for a map_linked_list_t.
//
//Fully checks if memory can be free'd to avoid double free's or corruption.
void free_map_list(map_linked_list_t **head);

//Free's allocated memory for win_settings, terraformer and my_map.
//If (the) pointer(s) point(s) to NULL, nothing happens with these/this one(s).
void free_game_structures(win_settings_t *win_settings,
                        map_formatter_t *terraformer,
                        map_linked_list_t **my_map);


#endif /* MY_WORLD_H_ */