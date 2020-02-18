/*
** EPITECH PROJECT, 2020
** perlin_noise
** File description:
** perlin noise generation
*/

#include <stdlib.h>
#include "map_generation.h"

int noise2(const int x, const int y, const size_t seed, const int do_free)
{
    static int *hash = NULL;
    int tmp = 0;

    if (!hash) {
        hash = get_hash();
        if (!hash)
            return (0);
    }
    if (hash && do_free == 1) {
        free(hash);
        hash = NULL;
        return (0);
    }
    tmp = hash[(y + seed) % 256];
    return (hash[(tmp + x) % 256]);
}

static float lin_inter(const float x, const float y, const float s)
{
    return (x + s * (y - x));
}

static float smooth_inter(const float x, const float y, const float s)
{
    return (lin_inter(x, y, s * s * (3 - 2 * s)));
}

static float noise_2d(const float x, const float y, const size_t seed)
{
    int x_int = x;
    int y_int = y;
    float x_frac = x - x_int;
    float y_frac = y - y_int;
    int s = noise2(x_int, y_int, seed, 0);
    int t = noise2(x_int + 1, y_int, seed, 0);
    int u = noise2(x_int, y_int + 1, seed, 0);
    int v = noise2(x_int + 1, y_int + 1, seed, 0);
    float low = smooth_inter(s, t, x_frac);
    float high = smooth_inter(u, v, x_frac);

    return (smooth_inter(low, high, y_frac));
}

float perlin_2d(const sfVector2f pos, const float freq,
                const int depth, const size_t seed)
{
    float xa = pos.x * freq;
    float ya = pos.y * freq;
    float amplitude = 1.0;
    float fin = 0;
    float diviser = 0.0;
    int index = 0;

    while (index < depth) {
        diviser += 256 * amplitude;
        fin += noise_2d(xa, ya, seed) * amplitude;
        amplitude /= 2;
        xa *= 2;
        ya *= 2;
        index += 1;
    }
    return (fin / diviser);
}
