/*
** EPITECH PROJECT, 2020
** mouse input
** File description:
** Mouse input handling
*/

#include <SFML/Window.h>
#include "my_world.h"

sfVector2f get_relative_mouse_pos(win_settings_t win_settings)
{
    static sfVector2i mouse_pos;
    static sfVector2f relative_mouse_pos;

    mouse_pos = sfMouse_getPositionRenderWindow(win_settings.window);
    relative_mouse_pos = sfRenderWindow_mapPixelToCoords(win_settings.window,
                        mouse_pos, win_settings.view);
    return (relative_mouse_pos);
}

void update_mouse_tool(win_settings_t *win_settings)
{
    win_settings->mouse_tool.pos = get_relative_mouse_pos(*win_settings);
    if (!(win_settings->mouse_tool.hold) &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
        win_settings->mouse_tool.click_pos = win_settings->mouse_tool.pos;
    }
    win_settings->mouse_tool.hold = sfMouse_isButtonPressed(sfMouseLeft);
}