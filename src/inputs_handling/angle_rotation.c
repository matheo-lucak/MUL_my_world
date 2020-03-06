/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** angle_rotation.c
*/

#include "my_world.h"

void rotate_up(presets_t *map_settings, sfBool *changed)
{
    map_settings->angles.y += map_settings->rotation_speed.y;
    *changed = sfTrue;
}

void rotate_down(presets_t *map_settings, sfBool *changed)
{
    map_settings->angles.y -= map_settings->rotation_speed.y;
    *changed = sfTrue;
}

void rotate_left(presets_t *map_settings, sfBool *changed)
{
    map_settings->angles.x -= map_settings->rotation_speed.x;
    *changed = sfTrue;
}

void rotate_right(presets_t *map_settings, sfBool *changed)
{
    map_settings->angles.x += map_settings->rotation_speed.x;
    *changed = sfTrue;
}