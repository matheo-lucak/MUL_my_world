/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_slider
*/

#include "my_world.h"
#include "game_object.h"
#include "vector_engine.h"

static void draw_slider_arrow(win_settings_t sets, game_obj_t *slider,
                                        float x_shift, float x_offset)
{
    game_obj_t *slider_arrow = find_game_object(slider, SLIDER_ARROW);
    sfVector2f pos;
    sfVector2i tpos = slider->comp[find_comp(slider, POS)]->v2i;

    tpos.x += -x_offset + x_shift;
    tpos.y += slider_arrow->view_box.width / 2;
    tpos.y *= sets.size.y / slider->view_box.height;
    pos = sfRenderWindow_mapPixelToCoords(sets.window,
            tpos, sets.view);
    set_pos(slider_arrow, pos.x, pos.y);
    sfSprite_setScale(slider_arrow->sprite, sets.scale);
    sfSprite_setRotation(slider_arrow->sprite, (180 * (x_shift)) / (x_offset) + 180);
    draw_game_object(sets, slider_arrow);
}

static void slide_slider(win_settings_t sets, game_obj_t *slider, float x_shift, float x_offset)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(slider->sprite);
    sfBool overlap = sfFloatRect_contains(&hitbox, sets.mouse_tool.pos.x,
                                                    sets.mouse_tool.pos.y);

    if (overlap && x_shift < x_offset - 3) {
        slider->comp[find_comp(slider, SHIFT)]->f += x_offset / 30;
    } else if (!overlap && x_shift > 0){
        slider->comp[find_comp(slider, SHIFT)]->f -= x_offset / 30;
    }
}

void draw_slider(win_settings_t sets, game_obj_t *slider)
{
    float x_offset;
    float x_shift;

    if (!slider || !(slider->comp))
        return ;
    x_offset = slider->comp[find_comp(slider, OFFSET)]->f;
    x_shift = slider->comp[find_comp(slider, SHIFT)]->f;
    sfSprite_setScale(slider->sprite,
                    vec2f(sets.scale.x,
                    sets.scale.y * sets.size.y / slider->view_box.height));
    set_pos(slider, sets.anchor.topleft.x +
                    sets.scale.x * (x_shift - x_offset),
                    sets.anchor.topleft.y);
    slide_slider(sets, slider, x_shift, x_offset);
    draw_game_object(sets, slider);
    draw_slider_arrow(sets, slider, x_shift, x_offset);
}