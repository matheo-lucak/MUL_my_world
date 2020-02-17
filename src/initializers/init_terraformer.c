/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_terraformer.c
*/

#include <stdlib.h>
#include "my_world.h"
#include "map_generation.h"

tile_t create_new_tile(void)
{
    tile_t new_tile;

    new_tile.matter_state = GRASS;
    new_tile.rstate.blendMode = sfBlendAdd;
    new_tile.rstate.transform = sfTransform_Identity;
    new_tile.shape_drawer = sfVertexArray_create();
}

tile_t **init_tile_map_2d(const sfVector2i map_size)
{
    tile_t **map_2d = malloc(sizeof(tile_t *) * (map_size.y));
    int y = 0;
    int x = 0;

    if (!map_2d)
        return (NULL);
    while (y < map_size.y - 1) {
        map_2d[y] = malloc(sizeof(tile_t) * (map_size.x));
        if (!(map_2d[y]))
            return (NULL);
        while (x < map_size.x - 1) {
            map_2d[y][x] = create_new_tile();
            if (!(map_2d[y][x].shape_drawer))
                return (NULL);
            x++;
        }
        x = 0;
        y++;
    }
    map_2d[y] = NULL;
    return (map_2d);
}

sfVector2f **init_map_2d(const sfVector2i map_size)
{
    int y = 0;
    sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * map_size.y);

    if (!map_2d)
        return (NULL);
    while (y < map_size.y) {
        map_2d[y] = malloc(sizeof(sfVector2f) * map_size.y);
        if (!(map_2d[y])) {
            free(map_2d);
            return (NULL);
        }
        y++;
    }
    return (map_2d);
}

sfBool init_terraformer(map_formatter_t *terraformer, size_t seed)
{
    terraformer->textures = init_textures();
    if (!(terraformer->textures))
        return (sfFalse);
    terraformer->shaders = init_shaders();
    if (!(terraformer->shaders)) {
        free_textures_array(terraformer->textures);
        return (sfFalse);
    }
    terraformer->map_settings.coords = (sfVector2i) {64, 64};
    terraformer->map_settings.angles = (sfVector2i) {45, 35};
    terraformer->map_settings.movement_speed = (sfVector2i){10, 10};
    terraformer->map_settings.rotation_speed = (sfVector2i){1, 1};
    terraformer->map_3d = generate_map(terraformer->map_settings.coords, seed);
    terraformer->map_2d = init_map_2d(terraformer->map_settings.coords);
    terraformer->v_map_2d = init_tile_map_2d(terraformer->map_settings.coords);
    if (!(terraformer->map_3d))
        return (sfFalse);
    return (sfTrue);
}