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

#define vec2f(x, y) (sfVector2f){x, y}
#define vec2i(x, y) (sfVector2i){x, y}

//An enum of each possible material a square can be.

typedef enum tile_matter_e {
    GRASS,
    STONE,
    GRAVEL,
    SAND,
    SNOW,
    WATER
} tile_matter_t;



//Settings that are helpful for the map rendering and angles of sight.
//
//Can be altered by the player.

typedef struct presets_s {
    sfVector2i size;
    sfVector2i angles;
    sfVector2i rotation_speed;
    sfVector2i movement_speed;
} presets_t;



//A square of the map node -> when linked together -> squares of the map



//A tile of the map

typedef struct tile_s {
    sfVertexArray *shape_drawer;
    sfShader *shader;
    sfRenderStates rstate;
    tile_matter_t matter_state;
} tile_t;



//linked list.

typedef struct map_linked_list_s {
    tile_t *tile;
    struct map_linked_list_s *next;
    struct map_linked_list_s *prev;
} map_linked_list_t;



//The alterer of coordinates of the points in the map.

typedef struct map_formatter_s {
    presets_t map_settings;
    float **map_3d;
    sfVector2f **map_2d;
    tile_t **tile_map_2d;
    sfShader **shaders;
    sfTexture **textures;
} map_formatter_t;


typedef struct fps_assets_s {
    sfText *fps_drawer;
    sfClock *clock;
    sfFont *fps_font;
    char *my_fps;
    sfTime time;
    unsigned int old_fps;
    unsigned int cur_fps;
} fps_assets_t;


typedef struct mouse_tool_s {
    sfVector2f pos;
    sfVector2f click_pos;
    sfBool hold;
} mouse_tool_t;


typedef struct anchor_s
{
    sfVector2f topleft;
    sfVector2f topright;
    sfVector2f bottomleft;
    sfVector2f bottomright;
} anchor_t;

//The window tool box.
typedef struct win_settings_s {
    sfRenderWindow *window;
    sfView *view;
    anchor_t anchor;
    sfVector2f size;
    sfVideoMode video_mode;
    sfEvent event;
    mouse_tool_t mouse_tool;
} win_settings_t;


/*
**                                 *********
**                                 | Usage |
**                                 *********
*/

//Prints the usage of my_world onto the stdout.
void usage(void);


/*
**                             ****************
**                             | Initializers |
**                             ****************
*/

//Initializes a Shaders array matching with the amount of textures..
//
//The array is NULL-terminated.
//
//If an error occurs -> returns NULL.
sfShader **init_shaders(sfTexture **textures);

//Initializes an array to every different sfTexture's.
//
//The array is NULL-terminated.
//
//If an error occurs -> returns NULL.
sfTexture **init_textures(void);

//Initializes a 2D array to stock map3D projection's values.
//Returns the allocated array if success.
//Returns NULL if an error occures.
sfVector2f **init_map_2d(const sfVector2i map_size);

//Initializes a 2D array of tiles to be displayed.
//Returns the allocated array if success.
//Returns NULL if an error occures.
tile_t **init_tile_map_2d(const sfVector2i map_size, sfTexture **textures,
                                                        sfShader **shaders);

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

//Initializes the win_settings struct
//terraformer struct and my_map linked_list.
//
//Returns sfTrue (1) if mallocs work.
//Returns sfFalse (0) otherwise.
sfBool init_game_structures(win_settings_t *win_settings,
                            map_formatter_t *terraformer,
                            fps_assets_t *resources_fps);

sfBool init_resources_fps(fps_assets_t *resources_fps);

/*
**                                  ******************
**                                  | Main game loop |
**                                  ******************
*/


//
void window_update(win_settings_t *win_settings,
                map_formatter_t *terraformer, fps_assets_t *resources_fps);

//Updates window settings such as
//
// Size
// Anchor
// Mouse settings
void udpate_window_settings(win_settings_t *win_settings);

//Checks if a window should stay opened or not.
//
//Returns sfTrue (1) if it should.
//Returns sfFalse (0) otherwise.
sfBool should_stay_opened(sfRenderWindow *window, sfEvent *event);

//Draws tile map 2D in RenderWindow
void draw_tile_map_2d(win_settings_t win_settings,
                        map_formatter_t *terraformer);

//Draws one circle in RenderWindow
void draw_circle(win_settings_t win_settings, map_formatter_t *terraformer,
                    sfVector2i pos);


//Magnet a number to a lenght if it's close enough:
//magnet: magnetize the number
//offset: range of the number to be magnetised
//acc: accuracy, use at least 100
void magnet_number(float *nb, float offset, int acc, float magnet);

//Main instance of the my_world edit game.
void my_world(void);


/*
**                                 *******************
**                                 | Map Linked List |
**                                 *******************
*/

//Allocates each map_linked_list_t node and links nodes in the list.
void create_map_list(map_linked_list_t **head,
                    const sfVector2i map_limits,
                    const sfTexture **textures,
                    const sfShader **shaders);

/*
**                                    ************
**                                    | Free'ers |
**                                    ************
*/

//Free's allocated memory from an arry sized.
//If the pointer points to NULL, nothing happens.
void free_array(void **array, const int size);

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
                        fps_assets_t *resources_fps);


void free_resources_fps(fps_assets_t *resources_fps);


#endif /* MY_WORLD_H_ */