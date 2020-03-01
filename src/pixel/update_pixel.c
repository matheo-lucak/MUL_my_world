/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** update_pixel
*/

#include "my_world.h"
#include "pixel.h"

void update_pixellist(win_settings_t win_settings, pixellist_t *pixels,
                                                    sfRectangleShape *rect)
{
    pixellist_t *tmp = pixels;

    if (!tmp || !rect)
        return ;
    do {
        update_pixel_physic(win_settings, tmp);
        sfRectangleShape_setPosition(rect, tmp->pos);
        sfRenderWindow_drawRectangleShape(win_settings.window, rect, NULL);
        tmp = tmp->next;
    } while (pixels != tmp && tmp);
}