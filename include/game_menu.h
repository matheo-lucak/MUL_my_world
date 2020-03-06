/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** A header for the menu assets
*/

#ifndef GAME_MENU_H_
#define GAME_MENU_H_

#include "game_object.h"
#include "pixel.h"

typedef struct menu_assets_s {
    game_obj_t *earth;
    pixellist_t *pixels;
    sfRectangleShape *pixel_drawer;
} menu_assets_t;

sfBool init_menu_assets(menu_assets_t *menu_assets);

sfRectangleShape *init_pixel_drawer(void);

#endif /* !GAME_MENU_H_ */
