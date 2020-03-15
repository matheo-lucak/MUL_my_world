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

static sfBool init_map_settings(map_formatter_t *ter)
{
    if (!ter)
        return (sfFalse);
    ter->map_settings.size = (sfVector2i) {32, 32};
    ter->map_settings.angles = (sfVector2i) {55, 70};
    ter->map_settings.movement_speed = (sfVector2i){10, 10};
    ter->map_settings.rotation_speed = (sfVector2i){1, 1};
    return (sfTrue);
}

static sfBool init_maps(map_formatter_t *ter, size_t seed)
{
    ter->map_3d = generate_map(ter->map_settings.size, seed);
    if (!(ter->map_3d))
        return (sfFalse);
    ter->map_2d = init_map_2d(ter->map_settings.size);
    if (!(ter->map_2d)) {
        free_array((void **)ter->map_3d,
                            ter->map_settings.size.x);
        return (sfFalse);
    }
    ter->tile_map_2d = init_tile_map_2d(ter->map_settings.size,
                                ter->textures, ter->shaders);
    if (!(ter->tile_map_2d)) {
        free_array((void **)ter->map_3d,
                            ter->map_settings.size.x);
        free_array((void **)ter->map_2d,
                            ter->map_settings.size.x);
        return (sfFalse);
    }
    return (sfTrue);
}

sfBool init_terraformer(map_formatter_t *ter, size_t seed)
{
    ter->textures = init_textures();
    if (!(ter->textures))
        return (sfFalse);
    ter->shaders = init_shaders(ter->textures);
    if (!(ter->shaders)) {
        free_textures_array(ter->textures);
        return (sfFalse);
    }
    if (!init_map_settings(ter))
        return (sfFalse);
    if (!init_maps(ter, seed))
        return (sfFalse);
    apply_biomes(ter);
    update_map_2d(ter);
    update_tile_map_2d(ter);
    return (sfTrue);
}