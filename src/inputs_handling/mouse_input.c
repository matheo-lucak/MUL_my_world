/*
** EPITECH PROJECT, 2020
** mouse input
** File description:
** Mouse input handling
*/

#include "my_world.h"

sfVector2f get_relative_mouse_pos(win_settings_t win_settings)
{
    sfVector2i m_pos;
    sfVector2f view_pos;
    sfVector2f relative_mouse_pos;
    sfVector2u window_size;
    sfVector2f scale;
    sfVector2f view_size;

    if (!(win_settings.window) || !(win_settings.view))
        return ((sfVector2f){0, 0});
    view_size = sfView_getSize(win_settings.view);
    view_pos = sfView_getCenter(win_settings.view);
    window_size = sfRenderWindow_getSize(win_settings.window);
    m_pos = sfMouse_getPositionRenderWindow(win_settings.window);
    scale.x = window_size.x / view_size.x;
    scale.y = window_size.y / view_size.y;
    relative_mouse_pos.x = (m_pos.x - (float)window_size.x / 2) / scale.x
    relative_mouse_pos.x += view_pos.x;
    relative_mouse_pos.y = (m_pos.y - (float)window_size.y / 2) / scale.y
    relative_mouse_pos.y += view_pos.y - 100;
    return (relative_mouse_pos);
}