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
float perlin2d(sfVector2f pos, float freq, int depth, size_t seed);

//Sub function of perlin2d.
//Set do_free to 1 to free the hash.
int noise2(int x, int y, int do_free);

//Generate float 3d map with perlin noise
float **generate_map(const unsigned int map_height,
                    const unsigned int map_width, size_t seed);

#endif /* MAP_GEN_H_ */