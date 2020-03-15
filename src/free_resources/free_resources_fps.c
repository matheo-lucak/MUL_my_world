/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Frees fps resources.
*/

#include <stdlib.h>
#include <my_world.h>

void free_resources_fps(fps_assets_t *fps_assets)
{
    if (fps_assets->clock)
        sfClock_destroy(fps_assets->clock);
    if (fps_assets->fps_drawer)
        sfText_destroy(fps_assets->fps_drawer);
    if (fps_assets->fps_font)
        sfFont_destroy(fps_assets->fps_font);
    fps_assets->fps_counter = 0;
}