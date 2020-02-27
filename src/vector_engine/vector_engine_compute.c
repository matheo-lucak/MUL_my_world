/*
** EPITECH PROJECT, 2020
** Vector_engine
** File description:
** 1
*/

#include <math.h>
#include "my.h"
#include "defender.h"

sfVector2f vec_add(sfVector2f vec1, sfVector2f vec2)
{
    sfVector2f res;

    res.x = vec1.x + vec2.x;
    res.y = vec1.y + vec2.y;
    return (res);
}

sfVector2f vec_sub(sfVector2f vec1, sfVector2f vec2)
{
    sfVector2f res;

    res.x = vec1.x - vec2.x;
    res.y = vec1.y - vec2.y;
    return (res);
}

sfVector2f vec_mult(sfVector2f vec1, float coeff)
{
    sfVector2f res;

    res.x = vec1.x * coeff;
    res.y = vec1.y * coeff;
    if (!res.x && !res.y)
        return ((sfVector2f){0, 0});
    return (res);
}

sfVector2f vec_div(sfVector2f vec1, float coeff)
{
    sfVector2f res;

    if (coeff == 0)
        return ((sfVector2f){0, 0});
    res.x = vec1.x / coeff;
    res.y = vec1.y / coeff;
    return (res);
}