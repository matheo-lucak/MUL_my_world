/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** project_iso_point
*/

#include <math.h>
#include "map_update.h"
#include "my_math.h"

sfVector2f project_iso_point(const sfVector3f pos_3d, sfVector2i map_size,
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
