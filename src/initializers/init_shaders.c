/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_shaders.c
*/

#include <stdlib.h>
#include "my.h"
#include "my_world.h"

sfShader **init_shaders(sfTexture **textures)
{
    int len = my_arrlen((void **)textures);
    int index = 0;
    sfShader **shaders = malloc(sizeof(sfShader *) * (len + 1));

    if (!shaders || len == 0)
        return (NULL);
    while (index < len) {
        shaders[index] = sfShader_createFromFile("assets/shaders/shader.vert",
                                        NULL,
                                        "assets/shaders/shader.frag");
        sfShader_setTextureUniform(shaders[index], "tex", textures[index]);
        sfShader_setVec2Uniform(shaders[index], "scale", (sfGlslVec2){1, 1});
        if (!shaders[index]) {
            free(shaders);
            return (NULL);
        }
        index++;
    }
    shaders[index] = NULL;
    return (shaders);
}