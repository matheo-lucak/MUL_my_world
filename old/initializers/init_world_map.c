/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_world_map.c
*/

#include "my_world.h"

map_t init_world_map(void)
{
    map_t world_map;

    world_map.presets = init_presets();
    world_map.not_edited = generate_map(world_map.presets.map_height,
                                        world_map.presets.map_width);
    world_map.edited = generate_map(world_map.presets.map_height,
                                    world_map.presets.map_width);
    world_map.map_2d = create_2d_map(world_map.presets, world_map.not_edited);
    world_map.lines = NULL;
    return (world_map);
}