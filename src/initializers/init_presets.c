/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_presets.c
*/

#include "my_world.h"

map_settings_t init_presets(void)
{
    map_settings_t presets;

    presets.map_height = 16;
    presets.map_width = 16;
    presets.angle_x = 45;
    presets.angle_y = 35;
    return (presets);
}