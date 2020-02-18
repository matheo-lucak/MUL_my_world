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
    terraformer->map_settings.size = (sfVector2i) {128, 128};
    terraformer->map_settings.angles = (sfVector2i) {45, 35};
    terraformer->map_settings.movement_speed = (sfVector2i){10, 10};
    terraformer->map_settings.rotation_speed = (sfVector2i){1, 1};
    terraformer->map_3d = generate_map(terraformer->map_settings.size, seed);
    terraformer->map_2d = init_map_2d(terraformer->map_settings.size);
    terraformer->tile_map_2d = init_tile_map_2d(terraformer->map_settings.size,
                                terraformer->textures, terraformer->shaders);
    if (!(terraformer->map_3d) || !(terraformer->map_2d) ||
        !(terraformer->tile_map_2d))
        return (sfFalse);
    update_map_2d(terraformer);
    update_tile_map_2d(terraformer);
    return (sfTrue);
}