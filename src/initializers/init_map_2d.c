/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_vertices_in_array.c
*/

#include <stdlib.h>
#include "my_world.h"

sfVertexArray ***init_map_2d(const int width, const int height)
{
    sfVertexArray ***map_2d = malloc(sizeof(sfVertexArray **) * (height));
    int x = 0;
    int y = 0;

    if (!map_2d)
        return (NULL);
    while (y < height - 1) {
        map_2d[y] = malloc(sizeof(sfVertexArray *) * (width));
        if (!map_2d[y])
            return (NULL);
        do {
            map_2d[y][x] = sfVertexArray_create();
            x += 1;
        } while (map_2d[y][x] && x < width - 1);
        map_2d[y][x] = NULL;
        x = 0;
        y += 1;
    }
    map_2d[y] = NULL;
    return (map_2d);
}