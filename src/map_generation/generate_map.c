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
#include "vector_engine.h"

void apply_perlin_noise_octave(float **map, int x, int y, const size_t seed)
{
    map[y][x] = perlin_2d(vec2f(x, y), 0.005, 10, seed) * 16;
    map[y][x] += perlin_2d(vec2f(x, y), 0.01, 5, seed) * 8;
    map[y][x] += perlin_2d(vec2f(x, y), 0.05, 5, seed) * 4;
    map[y][x] += perlin_2d(vec2f(x, y), 0.05, 5, seed) * 2;
    magnet_number(&(map[y][x]), 0.5, 100, 1);

}

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
            apply_perlin_noise_octave(map, x, y, seed);
        }
        y += 1;
    }
    noise2(0, 0, 0, 1);
    return (map);
}