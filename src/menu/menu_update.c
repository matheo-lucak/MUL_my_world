/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** menu_update
*/

#include "my_world.h"
#include "pixel.h"

void menu_update(win_settings_t *win_settings, pixellist_t **pixels)
{
    update_mouse_tool(win_settings);
    udpate_window_settings(win_settings);
    update_pixellist(*win_settings, pixels, rect);
}