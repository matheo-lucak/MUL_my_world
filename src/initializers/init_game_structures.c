/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_game_structures.c
*/

#include "my_world.h"

sfBool init_game_structures(map_formatter_t *terraformer,
                            fps_assets_t *resources_fps)
{
    if (!init_terraformer(terraformer, 120))
        return (sfFalse);
    if (!init_resources_fps(resources_fps))
        return (sfFalse);
    return (sfTrue);
}