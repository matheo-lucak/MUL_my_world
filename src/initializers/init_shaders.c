/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_shaders.c
*/

#include "my_world.h"

sfShader **init_shaders(void)
{
    sfShader **shaders = malloc(sizeof(sfShader *) * 2);

    if (!shaders)
        return (NULL);
    shaders[0] = sfShader_createFromFile("assets/shaders/shader.vert",
                                        NULL,
                                        "assets/shaders/shader.frag");
    if (!shaders[0]) {
        free(shaders);
        return (NULL);
    }
    shaders[1] = NULL;
    return (shaders);
}