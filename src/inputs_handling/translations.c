/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** translations.c
*/

#include "vector_engine.h"

sfVector2f transl_up(const sfVector2i mv_speed, const sfVector2f coeff)
{
    return (vec2f(0, mv_speed.y * -1 * coeff.y));
}

sfVector2f transl_down(const sfVector2i mv_speed, const sfVector2f coeff)
{
    return (vec2f(0, mv_speed.y * coeff.y));
}

sfVector2f transl_left(const sfVector2i mv_speed, const sfVector2f coeff)
{
    return (vec2f(mv_speed.x * -1 * coeff.x, 0));
}

sfVector2f transl_right(const sfVector2i mv_speed, const sfVector2f coeff)
{
    return (vec2f(mv_speed.x * coeff.x, 0));
}