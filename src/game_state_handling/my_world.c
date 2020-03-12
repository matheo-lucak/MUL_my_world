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

void draw_slider_arrow(win_settings_t sets, game_obj_t *slider)
{
    float x_shift = slider->comp[find_comp(slider, SHIFT)]->f;
    float x_offset = slider->comp[find_comp(slider, OFFSET)]->f;
    game_obj_t *slider_arrow = find_game_object(slider, SLIDER_ARROW);
    sfFloatRect hitbox = sfSprite_getGlobalBounds(slider->sprite);
    sfBool is_overlapping = sfFloatRect_contains(&hitbox, sets.mouse_tool.pos.x,
                                                    sets.mouse_tool.pos.y); 
    sfVector2f pos;
    sfVector2i tpos = slider->comp[find_comp(slider, POS)]->v2i;

    tpos.x += -x_offset + x_shift;
    pos = sfRenderWindow_mapPixelToCoords(sets.window,
            tpos, sets.view);
    set_pos(slider_arrow, pos.x, pos.y);
    sfSprite_setScale(slider_arrow->sprite, sets.scale);
    if (sfFloatRect_contains(&hitbox, sets.mouse_tool.pos.x, sets.mouse_tool.pos.y) && x_shift < x_offset - 3) {
        slider->comp[find_comp(slider, SHIFT)]->f += 3;
    } else if (!sfFloatRect_contains(&hitbox, sets.mouse_tool.pos.x, sets.mouse_tool.pos.y) && x_shift >= 0){
        slider->comp[find_comp(slider, SHIFT)]->f -= 3;
    }
    sfSprite_setRotation(slider_arrow->sprite, x_offset * (x_shift + 3) / 360 + 180);
    printf("%f && %f && %f\n", x_shift,  x_offset * (x_shift + 3) / 360 + 180, x_offset);
    draw_game_object(sets, slider_arrow);
}

void draw_slider(win_settings_t sets, game_obj_t *slider)
{
    float x_offset;
    float x_shift;

    if (!slider || !(slider->comp))
        return ;
    x_offset = slider->comp[find_comp(slider, OFFSET)]->f * sets.scale.x;
    x_shift = slider->comp[find_comp(slider, SHIFT)]->f * sets.scale.x;
    sfSprite_setScale(slider->sprite,
                    vec2f(sets.scale.x,
                    sets.scale.y * sets.size.y / slider->view_box.height));
    set_pos(slider, sets.anchor.topleft.x - x_offset + x_shift,
                                                sets.anchor.topleft.y);
    draw_game_object(sets, slider);
    draw_slider_arrow(sets, slider);
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