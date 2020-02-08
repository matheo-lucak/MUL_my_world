/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Projects a 3D point into a 2D one.
*/

#include <math.h>
#include "my_world.h"

sfVector2f project_iso_point(const int x, const int y, const int z,
                            sfVector2i angles)
{
    sfVector2f pos_2d;

    pos_2d.x = cos(my_radians(angles.x)) * x - sin(my_radians(angles.x)) * y;
    pos_2d.y = sin(my_radians(angles.y) + my_radians(90)) * y;
    pos_2d.y += cos(my_radians(angles.y)) * x - z;
    return (pos_2d);
}