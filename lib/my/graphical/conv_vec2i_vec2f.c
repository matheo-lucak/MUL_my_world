/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** conv_vec2i_vec2f.c
*/

#include <SFML/System/Vector2.h>

sfVector2f conv_vec2i_vec2f(const sfVector2i int_vector_2d)
{
    return ((sfVector2f){int_vector_2d.x, int_vector_2d.y});
}