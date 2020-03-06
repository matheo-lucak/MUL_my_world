/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Updates the pixel list
*/

#include "my_world.h"
#include "pixel.h"

void update_pixellist(win_settings_t sets, pixellist_t *pixels,
                        sfRectangleShape *rect)
{
    pixellist_t *tmp = pixels;

    if (!tmp || !rect)
        return;
    do {
        update_pixel_physic(sets, tmp);
        sfRectangleShape_setPosition(rect, tmp->pos);
        sfRenderWindow_drawRectangleShape(sets.window, rect, NULL);
        tmp = tmp->next;
    } while (pixels != tmp && tmp);
}