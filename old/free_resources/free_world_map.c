/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** free_world_map.c
*/

#include "my_world.h"

void free_world_map(map_t *world_map)
{
    if (world_map->map_2d)
        free_array((void **)world_map->map_2d, world_map->presets.map_height);
    if (world_map->not_edited)
        free_array((void **)world_map->not_edited,
                    world_map->presets.map_height);
    if (world_map->edited)
        free_array((void **)world_map->edited, world_map->presets.map_height);
}