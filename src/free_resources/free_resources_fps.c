/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** free_resources_fps.c
*/

#include <stdlib.h>
#include <my_world.h>

void free_resources_fps(fps_assets_t *resources_fps)
{
    if (resources_fps->clock)
        sfClock_destroy(resources_fps->clock);
    if (resources_fps->fps_drawer)
        sfText_destroy(resources_fps->fps_drawer);
    if (resources_fps->my_fps)
        free(resources_fps->my_fps);
}