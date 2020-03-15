/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Frees a shader array.
*/

#include <stdlib.h>
#include "my_world.h"

void free_shaders_array(sfShader **shaders)
{
    int index = 0;

    if (!(shaders))
        return;
    while (shaders[index]) {
        if (shaders[index])
            sfShader_destroy(shaders[index]);
        index += 1;
    }
    if (shaders)
        free(shaders);
}