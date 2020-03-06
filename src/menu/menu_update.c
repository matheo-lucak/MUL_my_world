/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** menu_update
*/

#include "my_world.h"
#include "input_handling.h"
#include "pixel.h"

void menu_update(win_settings_t *sets, pixellist_t *pixels)
{
    sfRectangleShape *rect = NULL;

    update_mouse_tool(sets);
    udpate_window_settings(sets);
    update_pixellist(*sets, pixels, rect);
}