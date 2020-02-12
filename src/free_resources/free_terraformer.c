/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** free_terraformer.c
*/

#include "my_world.h"

void free_terraformer(map_formatter_t *terraformer)
{
    if (!terraformer)
        return;
    free_textures_array(&(terraformer->textures));
    free_shaders_array(&(terraformer->shaders));
}