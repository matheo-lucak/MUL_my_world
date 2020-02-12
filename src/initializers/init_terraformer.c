/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_terraformer.c
*/

#include "my_world.h"
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
    terraformer->map_settings.map_x = 64;
    terraformer->map_settings.map_y = 64;
    terraformer->map_settings.angle_x = 45;
    terraformer->map_settings.angle_y = 35;
    terraformer->map_settings.movement_speed = (sfVector2i){10, 10};
    terraformer->map_settings.rotation_speed = (sfVector2i){1, 1};
    terraformer->map_3d = generate_map(terraformer->map_settings.map_x,
                                    terraformer->map_settings.map_y, seed);
    if (!(terraformer->map_3d))
        return (sfFalse);
    return (sfTrue);
}