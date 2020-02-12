/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** input handling
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
sfVector2f get_relative_mouse_pos(win_settings_t win_settings);

//Allows the player to translate camera on 2D plane.
const sfBool control_camera_view(presets_t map_settings, win_settings_t win_settings);

//Allows the player to rotate camera (Z axis).
//By default centered at map center.
const sfBool control_angle_view(presets_t *map_settings);

#endif /* INPUT_HANDLING_H_ */