/*
** EPITECH PROJECT, 2020
** generate map
** File description:
** perlin noise generation
*/

#include <stdlib.h>
#include <math.h>
#include "map_generation.h"
#include "my_world.h"

float **generate_map(const sfVector2i map_size,
                    const size_t seed)
{
    float **map = NULL;
    int x = 0;
    int y = 0;

    map = malloc(sizeof(float *) * map_size.y);
    if (!map)
        return (NULL);
    while (y < map_size.y) {
        map[y] = malloc(sizeof(float) * map_size.x);
        if (!(map[y]))
            return (NULL);
        for (x = 0; x < map_size.x; x += 1) {
            map[y][x] = exp(perlin_2d(vec2f(x, y), 0.05, 5, seed) * 5);
            magnet_number(&(map[y][x]), 0.5, 100, 1);
        }
        y += 1;
    }
    noise2(0, 0, 0, 1);
    return (map);
}