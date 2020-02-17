/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_v_map_2d
*/

#include "my_world.h"

void draw_tile_map_2d(sfRenderWindow *window, map_formatter_t *terraformer)
{
    int x = 0;
    int y = 0;

    while (y < terraformer->map_settings.size.y - 1) {
        for (x = 0; x < terraformer->map_settings.size.x - 1; x += 1)
            sfRenderWindow_drawVertexArray(window,
                terraformer->tile_map_2d[y][x].shape_drawer,
                &(terraformer->tile_map_2d[y][x].rstate));
        y += 1;
    }
}