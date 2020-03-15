/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** A header for the menu assets.
*/

#ifndef GAME_MENU_H_
#define GAME_MENU_H_

#include "game_object.h"
#include "pixel.h"
#include "my_world.h"

//A structure containing game_objects used into the menu
//and other elements.
typedef struct menu_assets_s {
    game_obj_t *earth;
    game_obj_t *background;
    game_obj_t *buttons;
    pixellist_t *pixels;
    sfRectangleShape *pixel_drawer;
} menu_assets_t;



//Initializes the menu_assets structure.
//
//Returns sfTrue if it could initialize,
//Returns sfFalse otherwise.
sfBool init_menu_assets(win_settings_t sets, menu_assets_t *menu_assets);



//Initializes the pixel drawer.
//
//Returns a pointer towards a sfRectangleShape if it could initialize,
//Returns sfFalse otherwise.
sfRectangleShape *init_pixel_drawer(void);



//Changes the color of the earth game_obj if the cursor mouse if hovering it.
//
//Returns sfTrue if the mouse clicked while hovering.
//Returns sfFalse otherwise.
sfBool hovering_earth_action(const game_obj_t *earth,
                            const mouse_tool_t mouse);



//Runs the menu.
//
//Returns sfTrue if the program needs to quit.
//Returns sfFalse otherwise.
sfBool run_menu(win_settings_t sets, menu_assets_t menu_assets);

#endif /* GAME_MENU_H_ */
