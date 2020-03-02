/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** save_map
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "my_world.h"

static void write_int_in_file(FILE *fptr, float nb)
{
    char *tmp = NULL;

    tmp = my_int_to_str((int)(nb) * 100);
    if (tmp) {
        fwrite(tmp, sizeof(char), my_strlen(tmp), fptr);
        fwrite(";", sizeof(char), 1, fptr);
        free(tmp);
    }
}

static sfBool write_map_data_in_file(FILE *fptr, float **map_3d, sfVector2i map_size)
{
    int x = 0;
    int y = 0;

    if (!fptr)
        return (sfFalse);
    while (y < map_size.y && map_3d && map_3d[y]) {
        while (x < map_size.x) {
            write_int_in_file(fptr, map_3d[y][x]);
            x += 1;
        }
        x = 0;
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
        tmp = NULL;
    }
    tmp = my_int_to_str(map_size.y);
    if (tmp) {
        fwrite(tmp, sizeof(char), my_strlen(tmp), fptr);
        fwrite("\n", sizeof(char), 1, fptr);
        free(tmp);
    }
    return (sfTrue);
}

sfBool save_map(map_formatter_t terraformer, char *file_name)
{
    FILE *fptr = NULL;

    if (!file_name || !(terraformer.map_3d))
        return (sfFalse);
    fptr = fopen(file_name, "w");
    if (!fptr)
        return (sfFalse);
    if(!write_map_size_in_file(fptr, terraformer.map_settings.size))
        return (sfFalse);
    if (!write_map_data_in_file(fptr, terraformer.map_3d,
                                terraformer.map_settings.size))
        return (sfFalse);
    return (sfTrue);
}