/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Saves the current map.
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "my_world.h"

static void write_int_in_file(FILE *fptr, const float nb)
{
    char *tmp = NULL;
    size_t len = 0;

    tmp = my_int_to_str((int)(nb) * 100);
    if (tmp) {
        len = my_strlen(tmp);
        if (fwrite(tmp, sizeof(char), len, fptr) != len)
            my_printf("Corrupting file \n");
        fwrite(";", sizeof(char), 1, fptr);
        free(tmp);
    }
}

static sfBool write_map_data_in_file(FILE *fptr, float **map_3d,
                                    const sfVector2i map_size)
{
    register size_t x = 0;
    register size_t y = 0;

    if (!fptr || !map_3d)
        return (sfFalse);
    while (y < (size_t)map_size.y) {
        for (x = 0; x < (size_t)map_size.x; x += 1) {
            write_int_in_file(fptr, map_3d[y][x]);
        }
        fwrite("\n", sizeof(char), 1, fptr);
        y += 1;
    }
    return (sfTrue);
}

static sfBool write_map_size_in_file(FILE *fptr, sfVector2i map_size)
{
    char *tmp = NULL;

    if (!fptr)
        return (sfFalse);
    tmp = my_int_to_str(map_size.x);
    if (tmp) {
        fwrite(tmp, sizeof(char), my_strlen(tmp), fptr);
        fwrite(";", sizeof(char), 1, fptr);
        free(tmp);
    }
    tmp = my_int_to_str(map_size.y);
    if (tmp) {
        fwrite(tmp, sizeof(char), my_strlen(tmp), fptr);
        fwrite("\n", sizeof(char), 1, fptr);
        free(tmp);
    }
    return (sfTrue);
}

sfBool save_map(map_formatter_t ter, char *file_name)
{
    FILE *fptr = NULL;

    if (!file_name || !(ter.map_3d))
        return (sfFalse);
    fptr = fopen(file_name, "w");
    if (!fptr)
        return (sfFalse);
    if (!write_map_size_in_file(fptr, ter.map_settings.size))
        return (sfFalse);
    if (!write_map_data_in_file(fptr, ter.map_3d, ter.map_settings.size))
        return (sfFalse);
    return (sfTrue);
}