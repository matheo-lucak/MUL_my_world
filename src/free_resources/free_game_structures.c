/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** free_game_structures.c
*/

#include "my_world.h"

void free_game_structures(win_settings_t *win_settings,
                        map_formatter_t *terraformer,
                        fps_assets_t *resources_fps)
{
    free_win_settings(win_settings);
    free_terraformer(terraformer);
    free_resources_fps(resources_fps);
}