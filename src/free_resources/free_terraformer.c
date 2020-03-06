/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** free_terraformer.c
*/

#include "my_world.h"

void free_terraformer(map_formatter_t *ter)
{
    if (!ter)
        return;
    free_textures_array(ter->textures);
    free_shaders_array(ter->shaders);
}