/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** creates an array of sfVector2f from an array of ints
*/

#include <stdlib.h>
#include "my_world.h"

static sfVector2f **allocate_map_2d(map_settings_t presets)
{
    sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * presets.map_height);
    int y = 0;

    if (!map_2d)
        return (NULL);
    while (y < presets.map_height) {
        map_2d[y] = malloc(sizeof(sfVector2f) * presets.map_width);
        y += 1;
    }
    return (map_2d);
}

sfVector2f **create_2d_map(map_settings_t presets, int **map_3d)
{
    sfVector2f **map_2d = allocate_map_2d(presets);
    int x = 0;
    int y = 0;

    if (!map_2d)
        return (NULL);
    while (y < presets.map_height) {
        for (x = 0; x < presets.map_width; x += 1)
            map_2d[y][x] = project_iso_point((sfVector3f){x, y, map_3d[y][x]},
                        (sfVector2f){presets.map_width, presets.map_height},
                        (sfVector2i){presets.angle_x, presets.angle_y});
        y += 1;
    }
    return (map_2d);
}