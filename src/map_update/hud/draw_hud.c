/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_hud
*/

#include "my_world.h"
#include "game_object.h"
#include "vector_engine.h"

void draw_hud(win_settings_t *sets, map_formatter_t *ter, hud_t *hud)
{
    if (!sets)
        return ;
    draw_fps(*sets, &(hud->fps_assets));
    draw_slider(sets, *ter, hud->slider);
    draw_save_button(sets, hud->save_button);
    draw_text_box(sets, ter, hud->save_button, hud->text_box);
    draw_sound_button(sets, hud->sound_button);
    draw_florian_the_toucan(sets, hud->florian);
}