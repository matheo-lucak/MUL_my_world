/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** A header for player's input
*/

#ifndef INPUT_HANDLING_H_

#define INPUT_HANDLING_H_

#include "my_world.h"

//Returns the mouse coordinates relative to:
//
//  -Window size
//  -View size
//  -View zoom
//  -View position
sfVector2f get_relative_mouse_pos(win_settings_t sets);

//Allows the player to translate camera on 2D plane.
sfBool control_camera_view(win_settings_t sets, presets_t map_settings,
                            fps_assets_t *fps_assets);

//Allows the player to rotate camera (Z axis).
//By default centered at map center.
sfBool control_angle_view(presets_t *map_settings);

//Updates mouse properties
void update_mouse_tool(win_settings_t *sets);

#endif /* INPUT_HANDLING_H_ */