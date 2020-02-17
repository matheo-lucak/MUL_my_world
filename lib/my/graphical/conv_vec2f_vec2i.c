/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** conv_vec2f_vec2i.c
*/

#include <SFML/System.h>

sfVector2i conv_vec2f_vec2i(const sfVector2f float_vector_2d)
{
    return ((sfVector2i){float_vector_2d.x, float_vector_2d.y});
}