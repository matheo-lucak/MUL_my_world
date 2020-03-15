/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Handles the camera angle and x-y pos that change the draw of the map.
*/
#include "my_world.h"
#include "input_handling.h"
#include "map_update.h"

void game_view_update(win_settings_t *sets, map_formatter_t *ter, hud_t *hud)
{
    if (!sets->paused)
        control_camera_view(*sets, ter->map_settings);
    if (!sets->paused && (control_angle_view(&(ter->map_settings))
        || sets->mouse_tool.hold)) {
        update_map_2d(ter);
        update_tile_map_2d(ter);
    }
    udpate_window_settings(sets);
    draw_tile_map_2d(sets, ter);
    draw_hud(sets, ter, hud);
    center_cam(sets, ter);
}