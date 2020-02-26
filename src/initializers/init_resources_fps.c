/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_resources_fps.c
*/

#include "my.h"
#include "my_world.h"

static sfBool exit_init_resources_fps(fps_assets_t *resources_fps)
{
    free_resources_fps(resources_fps);
    return (sfFalse);
}

sfBool init_resources_fps(fps_assets_t *resources_fps)
{
    resources_fps->clock = sfClock_create();
    if (!resources_fps->clock)
        return (sfFalse);
    resources_fps->fps_drawer = sfText_create();
    if (!resources_fps->fps_drawer)
        return (exit_init_resources_fps(resources_fps));
    resources_fps->my_fps = my_strdup("FPS: 0");
    if (!resources_fps->my_fps)
        return (exit_init_resources_fps(resources_fps));
    resources_fps->fps_font = sfFont_createFromFile("assets/font/Minecraft.ttf");
    if (!resources_fps->fps_font)
        return (exit_init_resources_fps(resources_fps));
    sfText_setFont(resources_fps->fps_drawer, resources_fps->fps_font);
    sfText_setPosition(resources_fps->fps_drawer, (sfVector2f){960, 540});
    sfText_setString(resources_fps->fps_drawer, resources_fps->my_fps);
    resources_fps->old_fps = 0;
    resources_fps->cur_fps = 0;
    return (sfTrue);
}