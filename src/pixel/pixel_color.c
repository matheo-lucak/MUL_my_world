/*
** EPITECH PROJECT, 2020
** $
** File description:
** pixel_color
*/

#include <stdio.h>
#include "my_world.h"
#include "pixel.h"
#include "vector_engine.h"

void update_pixel_color(win_settings_t sets, pixellist_t *pixel,
                                                sfRectangleShape *rect)
{
    sfColor color = sfBlue;
    int distance = 0;

    if (!pixel || !rect)
        return ;
    distance = vec_mag(vec_sub(pixel->pos, vec_mult(sets.size, 0.5)));
    if (distance < 0)
        distance *= -1;
    color = sfColor_fromInteger(distance * 1000000);
    color.a = 255;
    sfRectangleShape_setFillColor(rect, color);
}