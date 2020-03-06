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
    color.a = 255;
    color.g = 0;
    color.b = 255;
    if (distance <= 1500)
        color.r = 255 - 0.17 * distance;
    else
        color.r = 0;
    sfRectangleShape_setFillColor(rect, color);
}