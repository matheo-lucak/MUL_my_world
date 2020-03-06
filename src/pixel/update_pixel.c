/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Updates the pixel list
*/

#include "my_world.h"
#include "pixel.h"
#include "vector_engine.h"

void is_new_pixel(win_settings_t win_settings, pixellist_t **pixels)
{
    if (sfMouse_isButtonPressed(sfMouseRight)) {
        pixellist_add_x_pixels(pixels, (sfFloatRect) {
                                        win_settings.mouse_tool.pos.x - 1, win_settings.mouse_tool.pos.y - 1,
                                        win_settings.mouse_tool.pos.x, win_settings.mouse_tool.pos.y},
                                        1);
    }
}

void update_pixellist(win_settings_t sets, pixellist_t *pixels,
                        sfRectangleShape *rect)
{
    pixellist_t *tmp = pixels;

    if (!tmp || !rect)
        return ;
    is_new_pixel(sets, &pixels);
    do {
        update_pixel_physic(sets, tmp);
        sfRectangleShape_setPosition(rect, tmp->pos);
        sfRenderWindow_drawRectangleShape(sets.window, rect, NULL);
        tmp = tmp->next;
    } while (pixels != tmp && tmp);
}