/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** update_window
*/

#include "my.h"
#include "input_handling.h"
#include "my_world.h"

sfVector2f update_window_anchor(win_settings_t *win_settings)
{
    win_settings->anchor.topleft = sfRenderWindow_mapPixelToCoords
                    (win_settings->window, vec2i(0, 0), win_settings->view);
    win_settings->anchor.topright = sfRenderWindow_mapPixelToCoords
                    (win_settings->window, vec2i(win_settings->size.x, 0),
                    win_settings->view);
    win_settings->anchor.bottomleft = sfRenderWindow_mapPixelToCoords
                    (win_settings->window, vec2i(0, win_settings->size.y),
                    win_settings->view);
    win_settings->anchor.bottomright = sfRenderWindow_mapPixelToCoords
                    (win_settings->window,
                    vec2i(win_settings->size.x, win_settings->size.y),
                    win_settings->view);
}

void udpate_window_settings(win_settings_t *win_settings)
{
    sfVector2u size_u;

    if (!win_settings)
        return ;
    size_u = sfRenderWindow_getSize(win_settings->window);
    win_settings->size = (sfVector2f) {size_u.x, size_u.y};
    update_window_anchor(win_settings);
    update_mouse_tool(win_settings);
}