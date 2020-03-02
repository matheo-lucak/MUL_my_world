/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** hud
*/

#ifndef HUD_H_
#define HUD_H_

#include "game_object.h"
#include "pixel.h"

typedef struct hud_s
{
    pixellist_t *pixels;
    game_obj_t *earth;
    game_obj_t *buttons;
    game_obj_t *background;
    sfMusic *music;
} hud_t;


#endif /* !HUD_H_ */
