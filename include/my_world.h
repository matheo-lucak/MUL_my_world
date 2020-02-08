/*
** EPITECH PROJECT, 2019
** MUL_my_world_boostrap_2019
** File description:
** my_world_bootstrap.h
*/

#ifndef MY_WORLD_H_

#define MY_WORLD_H_

#include <SFML/System.h>
#include <SFML/Graphics.h>

typedef struct map_settings_s {
    unsigned int map_width;
    unsigned int map_height;
    int angle_x;
    int angle_y;
} map_settings_t;

typedef struct map_s {
    map_settings_t presets;
    int **not_edited;
    int **edited;
    sfVector2f **map_2d;
    sfVertexArray ***lines;
} map_t;

typedef struct win_settings_s {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfView *view;
} win_settings_t;

//Main instance of the game.
int my_world(void);


//Initializes the window.
win_settings_t init_window(void);
//
map_t init_world_map(void);
//Initializes the map presets.
map_settings_t init_presets(void);


//
float my_radians(int nb);


//Generates the map.
int **generate_map(const unsigned int map_height,
                    const unsigned int map_width);
//Controls the camera point of view.
void control_window_view(sfRenderWindow *window, sfView *view);

//Converts a 3D point into a sfVector2f.
sfVector2f project_iso_point(const int x, const int y, const int z,
                            sfVector2i angles);

//Draws the sfVector2f array onto the window.
void draw_2d_map(sfRenderWindow *window, map_settings_t presets,
                sfVector2f **map_2d);

//Creates an array of sfVector2f containing 2D positions of the vertices of the map.
sfVector2f **create_2d_map(map_settings_t presets, int **map_3d);

//Returns a sfVertexArray containing two points linked by a line.
sfVertexArray *create_line (sfVector2f *p1, sfVector2f *p2, sfVector2f *p3, sfColor color);



//
void free_win_sets(win_settings_t *win_sets);
//
void free_world_map(map_t *world_map);
//Frees allocated memory for the int array map.
void free_array(void **array, const unsigned int size);

#endif /* MY_WORLD_H_ */