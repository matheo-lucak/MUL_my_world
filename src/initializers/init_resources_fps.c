/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_resources_fps.c
*/

#include "my.h"
#include "my_world.h"

static sfBool exit_init_resources_fps(fps_assets_t *fps_assets)
{
    free_resources_fps(fps_assets);
    return (sfFalse);
}

sfBool init_resources_fps(fps_assets_t *fps_assets)
{
    fps_assets->clock = sfClock_create();
    if (!fps_assets->clock)
        return (sfFalse);
    fps_assets->fps_drawer = sfText_create();
    if (!fps_assets->fps_drawer)
        return (exit_init_resources_fps(fps_assets));
    fps_assets->fps_font = sfFont_createFromFile("assets/font/minecraft.ttf");
    if (!fps_assets->fps_font)
        return (exit_init_resources_fps(fps_assets));
    sfText_setFont(fps_assets->fps_drawer, fps_assets->fps_font);
    fps_assets->fps_counter = 0;
    return (sfTrue);
}