/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_terraformer.c
*/

#include <stdlib.h>
#include "my_world.h"
#include "map_update.h"
#include "map_generation.h"

static sfBool init_map_settings(map_formatter_t *terraformer)
{
    if (!terraformer)
        return (sfFalse);
    terraformer->map_settings.size = (sfVector2i) {2, 2};
    terraformer->map_settings.angles = (sfVector2i) {45, 35};
    terraformer->map_settings.movement_speed = (sfVector2i){10, 10};
    terraformer->map_settings.rotation_speed = (sfVector2i){1, 1};
    return (sfTrue);
}

static sfBool init_maps(map_formatter_t *terraformer, size_t seed)
{
    terraformer->map_3d = generate_map(terraformer->map_settings.size, seed);
    if (!(terraformer->map_3d))
        return (sfFalse);
    terraformer->map_2d = init_map_2d(terraformer->map_settings.size);
    if (!(terraformer->map_2d)) {
        free_array((void **)terraformer->map_3d,
                            terraformer->map_settings.size.x);
        return (sfFalse);
    }
    terraformer->tile_map_2d = init_tile_map_2d(terraformer->map_settings.size,
                                terraformer->textures, terraformer->shaders);
    if (!(terraformer->tile_map_2d)) {
        free_array((void **)terraformer->map_3d,
                            terraformer->map_settings.size.x);
        free_array((void **)terraformer->map_2d,
                            terraformer->map_settings.size.x);
        return (sfFalse);
    }
    return (sfTrue);
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
    if (!init_map_settings(terraformer))
        return (sfFalse);
    if (!init_maps(terraformer, seed))
        return (sfFalse);
    update_map_2d(terraformer);
    update_tile_map_2d(terraformer);
    return (sfTrue);
}