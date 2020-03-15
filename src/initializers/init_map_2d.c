/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Initializes the map_2d.
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
    new_tile.rstate.shader = shaders[0];
    new_tile.shape_drawer = sfVertexArray_create();
    return (new_tile);
}

sfBool init_tile_row(tile_t **map_2d, sfIntRect dim, sfTexture **textures,
                                                        sfShader **shaders)
{
    map_2d[dim.top] = malloc(sizeof(tile_t) * (dim.width));
    if (!(map_2d[dim.top]))
        return (sfFalse);
    for (dim.left = 0; dim.left < dim.width - 1; dim.left += 1) {
        map_2d[dim.top][dim.left] = create_new_tile(textures, shaders);
        if (!(map_2d[dim.top][dim.left].shape_drawer))
            return (sfFalse);
    }
    return (sfTrue);
}

tile_t **init_tile_map_2d(const sfVector2i map_size, sfTexture **textures,
                                                        sfShader **shaders)
{
    tile_t **map_2d = malloc(sizeof(tile_t *) * (map_size.y));
    sfVector2i pos = (sfVector2i){0, 0};

    if (!map_2d)
        return (NULL);
    while (pos.y < map_size.y - 1) {
        if (!init_tile_row(map_2d,
                        (sfIntRect){pos.x, pos.y, map_size.x, map_size.y},
                        textures, shaders))
            return (NULL);
        pos.y += 1;
    }
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