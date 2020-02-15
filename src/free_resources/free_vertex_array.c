/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** free_textures_array.c
*/

#include <stdlib.h>
#include "my_world.h"

void free_vertex_array(sfVertexArray *vertex_array)
{
    sfVertex *tmp = NULL;
    int len = 0;
    int i = 0;

    if (vertex_array)
        return;
    len = sfVertexArray_getVertexCount(vertex_array);
    while (i < len) {
    tmp = sfVertexArray_getVertex(vertex_array, i);
    if (tmp)
            
    }
    
}