/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Projects a 3D point into a 2D one.
*/

#include <math.h>
#include "my_world.h"

sfVector2f project_iso_point(const sfVector3f pos_3d, sfVector2f map_size,
                            sfVector2i angles)
{
    sfVector2f pos_2d;
    sfVector3f coeff = pos_3d;

    coeff.x = (pos_3d.x - (map_size.x / 2));
    coeff.y = (pos_3d.y - (map_size.y / 2));
    pos_2d.x = cos(my_radians(angles.x)) * coeff.x;
    pos_2d.x -= sin(my_radians(angles.x)) * coeff.y;
    pos_2d.y = sin(my_radians(angles.y) + my_radians(90)) * coeff.y;
    pos_2d.y += cos(my_radians(angles.y)) * coeff.x - coeff.z;
    return (pos_2d);
}