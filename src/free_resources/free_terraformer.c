/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Frees a map_formatter_t structure.
*/

#include <stdlib.h>
#include "my_world.h"

void free_tile_map_2d(tile_t **tile_map_2d, sfVector2i size)
{
    int x = 0;
    int y = 0;

    if (!tile_map_2d)
        return ;
    while (y < size.y && tile_map_2d[y]) {
        while (x < size.x && tile_map_2d[y][x].shape_drawer) {
            sfVertexArray_destroy(tile_map_2d[y][x].shape_drawer);
            x += 1;
        }
        free(tile_map_2d[y]);
        x = 0;
        y += 1;
    }
    free(tile_map_2d);
}

void free_terraformer(map_formatter_t *ter)
{
    if (!ter)
        return;
    free_textures_array(ter->textures);
    free_shaders_array(ter->shaders);
    free_array((void **)ter->map_3d, ter->map_settings.size.y);
    free_array((void **)ter->map_2d, ter->map_settings.size.y);
}