/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_hud
*/

#include "my_world.h"
#include "game_object.h"
#include "vector_engine.h"

void draw_hud(win_settings_t *sets, hud_t *hud)
{
    if (!sets)
        return ;
    draw_fps(*sets, &(hud->fps_assets));
    draw_slider(sets, hud->slider);
}