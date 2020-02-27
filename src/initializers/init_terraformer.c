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

static void apply_altitude(map_formatter_t *terraformer, int x, int y)
{
    float average = 0;

    if (!terraformer)
        return ;
    average += terraformer->map_3d[y][x];
    average += terraformer->map_3d[y + 1][x];
    average += terraformer->map_3d[y][x + 1];
    average += terraformer->map_3d[y + 1][x + 1];
    average /= 4;
    if (average > 25 && average < 40) {
        terraformer->tile_map_2d[y][x].matter_state = STONE;
    } else if (average > 40) {
        terraformer->tile_map_2d[y][x].matter_state = SNOW;
    } else {
        terraformer->tile_map_2d[y][x].matter_state = GRASS;
    }
}

static void apply_biomes(map_formatter_t *terraformer)
{
    int x = 0;
    int y = 0;

    while (y < terraformer->map_settings.size.y - 1) {
        for (x = 0; x < terraformer->map_settings.size.x - 1; x += 1) {
            apply_altitude(terraformer, x, y);
        }
        y += 1;
    }
}


static sfBool init_map_settings(map_formatter_t *terraformer)
{
    if (!terraformer)
        return (sfFalse);
    terraformer->map_settings.size = (sfVector2i) {32, 32};
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
    terraformer->shaders = init_shaders(terraformer->textures);
    if (!(terraformer->shaders)) {
        free_textures_array(terraformer->textures);
        return (sfFalse);
    }
    if (!init_map_settings(terraformer))
        return (sfFalse);
    if (!init_maps(terraformer, seed))
        return (sfFalse);
    apply_biomes(terraformer);
    update_map_2d(terraformer);
    update_tile_map_2d(terraformer);
    return (sfTrue);
}