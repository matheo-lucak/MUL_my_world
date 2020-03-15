/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Frees game structures.
*/

#include "my_world.h"

void free_game_structures(map_formatter_t *ter,
                        fps_assets_t *fps_assets)
{
    free_terraformer(ter);
    free_resources_fps(fps_assets);
}