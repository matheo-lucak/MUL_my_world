/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** map_generation.h
*/

#ifndef MAP_GEN_H_

#define MAP_GEN_H_

#include <SFML/System/Vector2.h>

//Generate hash from file.
int *get_hash(void);

//Returns a random smooth number generated with hash and seed.
float perlin2d(const sfVector2f pos, const float freq,
                const int depth, const size_t seed);

//Sub function of perlin2d.
//Set do_free to 1 to free the hash.
int noise2(const int x, const int y, const size_t seed,
            const int do_free);

//Generate float 3d map with perlin noise
float **generate_map(const sfVector2i map_size,
                    const size_t seed);

#endif /* MAP_GEN_H_ */