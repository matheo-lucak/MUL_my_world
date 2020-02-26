/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_vertices_in_array.c
*/

#include <stdlib.h>
#include "my.h"
#include "my_world.h"

tile_t create_new_tile(sfTexture **textures, sfShader **shaders)
{
    tile_t new_tile;

    new_tile.matter_state = GRASS;
    new_tile.rstate.blendMode = sfBlendAlpha;
    new_tile.rstate.transform = sfTransform_Identity;
    if (!(textures) || !(textures[0]) || !(shaders) || !(shaders[0])) {
        new_tile.shape_drawer = NULL;
        return (new_tile);
    }
    new_tile.rstate.texture = textures[0];
    my_memcpy(&(new_tile.rstate.shader), *shaders, sizeof(sfShader *));
    new_tile.shape_drawer = sfVertexArray_create();
    return (new_tile);
}

tile_t **init_tile_map_2d(const sfVector2i map_size, sfTexture **textures,
                                                        sfShader **shaders)
{
    tile_t **map_2d = malloc(sizeof(tile_t *) * (map_size.y));
    sfVector2i pos = (sfVector2i){0, 0};

    if (!map_2d)
        return (NULL);
    while (pos.y < map_size.y - 1) {
        map_2d[pos.y] = malloc(sizeof(tile_t) * (map_size.x));
        if (!(map_2d[pos.y]))
            return (NULL);
        for (pos.x = 0; pos.x < map_size.x - 1; pos.x += 1) {
            map_2d[pos.y][pos.x] = create_new_tile(textures, shaders);
            if (!(map_2d[pos.y][pos.x].shape_drawer))
                return (NULL);
        }
        pos.y += 1;
    }
    map_2d[pos.y] = NULL;
    return (map_2d);
}

sfVector2f **init_map_2d(const sfVector2i map_size)
{
    sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * map_size.y);
    int y = 0;

    if (!map_2d)
        return (NULL);
    while (y < map_size.y) {
        map_2d[y] = malloc(sizeof(sfVector2f) * map_size.y);
        if (!(map_2d[y])) {
            free(map_2d);
            return (NULL);
        }
        y += 1;
    }
    return (map_2d);
}