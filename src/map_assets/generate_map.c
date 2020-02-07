/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** generate_map.c
*/

#include <stdlib.h>
#include <my_world.h>

static void assert_height_value(int *value, const int x, const int y)
{
    if ((rand() % (1 - 30) + 1) == 2)
        *value = rand() % (1 - 10) + 1;
    else
        *value = 0;
}

int **generate_map(const unsigned int map_height,
                    const unsigned int map_width)
{
    int **map = NULL;
    int x = 0;
    int y = 0;

    map = malloc(sizeof(int *) * map_height);
    if (!map)
        return (NULL);
    while (y < map_height) {
        map[y] = malloc(sizeof(int) * map_width);
        for (x = 0; x < map_width; x += 1)
            assert_height_value(&(map[y][x]), x, y);
        y += 1;
    }
    return (map);
}