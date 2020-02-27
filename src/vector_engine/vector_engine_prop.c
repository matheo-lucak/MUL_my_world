/*
** EPITECH PROJECT, 2020
** Vector_engine
** File description:
** 1
*/

#include <math.h>
#include <SFML/System/Vector2.h>
#include "my.h"

float vec_mag(sfVector2f vec1)
{
    float mag = 0;

    mag = sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y));
    return (mag);
}

sfVector2f vec_norm(sfVector2f vec1)
{
    sfVector2f res;
    float mag = vec_mag(vec1);

    res.x = vec1.x / mag;
    res.y = vec1.y / mag;
    return (res);
}

sfVector2f vec_lim(sfVector2f vec1, sfVector2f top_lim, sfVector2f bottom_lim)
{
    sfVector2f res = vec1;

    if (res.x > top_lim.x)
        res.x = top_lim.x;
    else if (res.x < bottom_lim.x)
        res.x = bottom_lim.x;
    if (res.y > top_lim.y)
        res.y = top_lim.y;
    else if (res.y < bottom_lim.y)
        res.y = bottom_lim.y;
    return (res);
}