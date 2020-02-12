/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** creates linked lines between two points.
*/

#include "my_world.h"

static sfVector2f vector_mul(sfVector2f vector, int coeff)
{
    return ((sfVector2f){vector.x * coeff, vector.y * coeff});
}

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2, sfVector2f *point3, sfColor color)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVector2f point1_resized = vector_mul(*point1, 100);
    sfVector2f point2_resized = vector_mul(*point2, 100);
    sfVector2f point3_resized = vector_mul(*point3, 100);
    sfVertex vertex1 = {.position = point1_resized, .color = color, .texCoords = (sfVector2f){0, 0}};
    sfVertex vertex2 = {.position = point2_resized, .color = color, .texCoords = (sfVector2f){100, 0}};
    sfVertex vertex3 = {.position = point3_resized, .color = color, .texCoords = (sfVector2f){0, 100}};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    return (vertex_array);
}