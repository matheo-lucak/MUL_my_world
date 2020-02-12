/*
** EPITECH PROJECT, 2020
** generate map
** File description:
** perlin noise generation
*/

#include <stddef.h>
#include "map_generation.h"

float **generate_map(const unsigned int map_height,
                    const unsigned int map_width, size_t seed)
{
    float **map = NULL;
    int x = 0;
    int y = 0;

    map = malloc(sizeof(float *) * map_height);
    if (!map)
        return (NULL);
    while (y < map_height) {
        map[y] = malloc(sizeof(float) * map_width);
        if (!(map[y]))
            return (NULL);
        for (x = 0; x < map_width; x += 1) {
            map[y][x] = perlin2d((sfVector2f){x, y}, 0.05, 10, seed);
        }
        y += 1;
    }
    noise2(0, 0, 1);
    return (map);
}