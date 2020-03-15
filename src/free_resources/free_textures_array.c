/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Frees an array of textures.
*/

#include <stdlib.h>
#include "my_world.h"

void free_textures_array(sfTexture **textures)
{
    int index = 0;

    if (!textures)
        return;
    while (textures[index]) {
        if (textures[index])
            sfTexture_destroy(textures[index]);
        index += 1;
    }
    if (textures)
        free(textures);
}