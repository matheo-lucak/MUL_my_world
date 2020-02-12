/*
** EPITECH PROJECT, 2020
** perlin_noise
** File description:
** perlin noise generation
*/

#include <stddef.h>
#include "map_generation.h"

int noise2(int x, int y, size_t seed, int do_free)
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
    return hash[(tmp + x) % 256];
}

float lin_inter(float x, float y, float s)
{
    return (x + s * (y-x));
}

float smooth_inter(float x, float y, float s)
{
    
    return (lin_inter(x, y, s * s * (3-2*s)));
}

float noise2d(float x, float y, size_t seed)
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

float perlin2d(sfVector2f pos, float freq, int depth, size_t seed)
{
    float xa = pos.x * freq;
    float ya = pos.y * freq;
    float amp = 1.0;
    float fin = 0;
    float div = 0.0;
    int i = 0;

    while (i < depth) {
        div += 256 * amp;
        fin += noise2d(xa, ya, seed) * amp;
        amp /= 2;
        xa *= 2;
        ya *= 2;
        i++;
    }
    return (fin / div);
}
