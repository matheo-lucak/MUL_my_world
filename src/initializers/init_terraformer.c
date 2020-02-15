/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_terraformer.c
*/

#include <stdlib.h>
#include "my_world.h"
#include "map_generation.h"

sfVertexArray ***init_v_map_2d(const int width,
                                const int height)
{
    sfVertexArray ***map_2d = malloc(sizeof(sfVertexArray **) * (height));
    int y = 0;
    int x = 0;

    if (!map_2d)
        return (NULL);
    while (y < height - 1) {
        map_2d[y] = malloc(sizeof(sfVertexArray *) * (width));
        if (!(map_2d[y]))
            return (NULL);
        do {
            map_2d[y][x] = sfVertexArray_create();
        }
        while (map_2d[y][x] && x++ < width - 1);
        map_2d[y][width - 1] = NULL;
        x = 0;
        y++;
    }
    map_2d[y] = NULL;
    return (map_2d);
}

sfVector2f **init_map_2d(const int width,
                            const int height)
{
    int y = 0;
    sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * height);

    if (!map_2d)
        return (NULL);
    while (y < height) {
        map_2d[y] = malloc(sizeof(sfVector2f) * width);
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
    terraformer->map_settings.map_x = 64;
    terraformer->map_settings.map_y = 64;
    terraformer->map_settings.angle_x = 45;
    terraformer->map_settings.angle_y = 35;
    terraformer->map_settings.movement_speed = (sfVector2i){10, 10};
    terraformer->map_settings.rotation_speed = (sfVector2i){1, 1};
    terraformer->map_3d = generate_map(terraformer->map_settings.map_x,
                                    terraformer->map_settings.map_y, seed);
    terraformer->map_2d = init_map_2d((int)terraformer->map_settings.map_x,
                                        (int)terraformer->map_settings.map_y);
    terraformer->v_map_2d = init_v_map_2d((int)terraformer->map_settings.map_x,
                                        (int)terraformer->map_settings.map_y);
    if (!(terraformer->map_3d))
        return (sfFalse);
    return (sfTrue);
}