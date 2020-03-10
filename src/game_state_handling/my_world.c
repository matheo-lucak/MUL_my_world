/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Main instance of the game.
*/

#include <stdlib.h>
#include "my.h"
#include "my_world.h"
#include "game_object.h"
#include "vector_engine.h"

void draw_slider(win_settings_t sets, game_obj_t *slider)
{
    sfSprite_setScale(slider->sprite, vec2f(1, sets.size.y / slider->view_box.height));
    sfSprite_scale(slider->sprite, sets.scale);
    set_pos(slider, sets.anchor.topleft.x, sets.anchor.topleft.y);
    draw_game_object(sets, slider);
}

void draw_hud(win_settings_t sets, hud_t *hud)
{
    draw_fps(sets, &(hud->fps_assets));
    draw_slider(sets, hud->slider);
}

sfBool my_world(win_settings_t *sets)
{
    hud_t hud;
    map_formatter_t ter;
    sfBool goback_menu = sfFalse;

    if (!init_game_structures(&ter, &hud))
        return (sfFalse);
    sfMusic_setVolume(sets->main_track, 45);
    sfView_setCenter(sets->view, vec2f(0, 0));
    while (game_state_checker(sets->window, &sets->event, &goback_menu)) {
        sfRenderWindow_clear(sets->window, sfBlack);
        game_view_update(sets, &ter);
        draw_hud(*sets, &hud);
        sfRenderWindow_display(sets->window);
    }
    free_game_structures(&ter, &(hud.fps_assets));
    return (goback_menu);
}