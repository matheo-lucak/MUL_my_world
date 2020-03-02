/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** open_map
*/

#include <stdlib.h>
#include <fcntl.h>
#include <SFML/System/Vector2.h>
#include "my.h"

static sfBool set_map_size(int fd, sfVector2i *map_size)
{
    char **parsed_line = NULL;

    if (!map_size)
        return (sfFalse);
    parsed_line = my_str_to_word_array(get_next_line(fd), ";", 1);
    if (!parsed_line)
        return (sfFalse);
    if (my_arrlen((void **)parsed_line) != 2)
        return (sfFalse);
    map_size->x = my_getnbr(parsed_line[0]);
    map_size->y = my_getnbr(parsed_line[1]);
    my_free_arr(parsed_line);
    if (map_size->x <= 0 || map_size->y <= 0)
        return (sfFalse);
    return (sfTrue);
}

static float *fill_float_array(int fd, int map_width)
{
    char **parsed_line = NULL;
    float *new_line = NULL;
    int x = 0;

    parsed_line = my_str_to_word_array(get_next_line(fd), ";", 1);
    if (!parsed_line)
        return (NULL);
    if (my_arrlen((void **)parsed_line) != map_width)
        return (NULL);
    while (x < map_width) {
        if (!(parsed_line[x]))
            return (NULL);
        new_line[x] = (float)my_getnbr(parsed_line[x]) * 100;
        x += 1;
    }
    my_free_arr(parsed_line);
    return (new_line);
}

float **open_map(char *file_name)
{
    int fd = 0;
    float **map_3d = NULL;
    sfVector2i map_size = {0, 0};
    int y = 0;

    if (!file_name)
        return (NULL);
    fd = open(file_name, O_RDONLY);
    if (!set_map_size(fd, &map_size))
        return (NULL);
    map_3d = malloc(sizeof(float *) * map_size.y);
    if (!map_3d)
        return (NULL);
    while (y < map_size.y) {
        map_3d[y] = fill_float_array(fd, map_size.x);
        if (!(map_3d[y]))
            return (NULL);
        y += 1;
    }
    return (map_3d);
}