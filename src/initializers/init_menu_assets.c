/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_menu_assets
*/

#include "my_world.h"
#include "game_menu.h"
#include "game_object.h"
#include "vector_engine.h"

sfRectangleShape *init_pixel_drawer(void)
{
    sfRectangleShape *pixel_drawer = sfRectangleShape_create();

    if (!pixel_drawer)
        return (NULL);
    sfRectangleShape_setSize(pixel_drawer, vec2f(4, 4));
    return (pixel_drawer);
}

sfBool init_menu_assets(menu_assets_t *menu_assets)
{
    if (!menu_assets)
        return (sfFalse);
    pixellist_add_x_pixels(&(menu_assets->pixels), vec2f(10, 10), 200);
    menu_assets->pixel_drawer = init_pixel_drawer();
    if (!menu_assets->pixel_drawer)
        return (sfFalse);
    menu_assets->earth = create_game_obj(EARTH);
    if (!(menu_assets->earth))
        return (sfFalse);
    return (sfTrue);
}