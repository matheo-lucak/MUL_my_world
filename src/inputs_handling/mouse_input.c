/*
** EPITECH PROJECT, 2020
** mouse input
** File description:
** Mouse input handling
*/

#include <SFML/Window.h>
#include "my_world.h"

sfVector2f get_relative_mouse_pos(win_settings_t sets)
{
    static sfVector2i mouse_pos;
    static sfVector2f relative_mouse_pos;

    mouse_pos = sfMouse_getPositionRenderWindow(sets.window);
    relative_mouse_pos = sfRenderWindow_mapPixelToCoords(sets.window,
                        mouse_pos, sets.view);
    return (relative_mouse_pos);
}

void update_mouse_tool(win_settings_t *sets)
{
    sets->mouse_tool.pos = get_relative_mouse_pos(*sets);
    if (!(sets->mouse_tool.hold) && sfMouse_isButtonPressed(sfMouseLeft))
        sets->mouse_tool.click_pos = sets->mouse_tool.pos;
    sets->mouse_tool.hold = sfMouse_isButtonPressed(sfMouseLeft);
}