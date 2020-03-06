/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_game_structures.c
*/

#include "my_world.h"

sfBool init_game_structures(map_formatter_t *ter,
                            fps_assets_t *fps_assets)
{
    if (!init_terraformer(ter, get_randomnb(1, 255)))
        return (sfFalse);
    if (!init_resources_fps(fps_assets))
        return (sfFalse);
    return (sfTrue);
}