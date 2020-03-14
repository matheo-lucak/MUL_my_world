/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_view_mode_button
*/

#include "my_world.h"
#include "game_object.h"
#include "vector_engine.h"

static view_mode_t find_view_mode_from_button_type(elem_t type)
{
    static const view_mode_t mode_pattern[] = {VIEW_TEXTURE,
                                                    VIEW_LINE,
                                                    VIEW_PIN, 0};
    static const elem_t type_pattern[] = {TEXTURE_VIEW_BUTTON,
                                            VERTEX_VIEW_BUTTON,
                                            PIN_VIEW_BUTTON, 0};
    int index = 0;

    while (type_pattern[index]) {
        if (type_pattern[index] == type)
            return (mode_pattern[index]);
        index += 1;
    }
    return (0);
}

static void link_view_button_function(win_settings_t *sets, game_obj_t *edit_b)
{
    sfFloatRect hitbox = {0, 0, 0, 0};
    sfBool overlap = 0;
    view_mode_t mode = find_view_mode_from_button_type(edit_b->type);
    sfSound *sound = NULL;

    if (!sets || !edit_b)
        return ;
    hitbox = sfSprite_getGlobalBounds(edit_b->sprite);
    overlap = sfFloatRect_contains(&hitbox, sets->mouse_tool.pos.x,
                                                    sets->mouse_tool.pos.y);
    if (overlap && sets->mouse_tool.click) {
        sound = edit_b->comp[find_comp(edit_b, SOUND)]->sound;
        if (sound)
            sfSound_play(sound);
        if (is_view_mode(sets->mode, mode))
            unset_view_mode(&(sets->mode), mode);
        else
            set_view_mode(&(sets->mode), mode);
    }
}

static void draw_view_button_by_type(win_settings_t *sets, game_obj_t *slider,
                                        float x_offset, elem_t type) 
{
    game_obj_t *edit_b = find_game_object(slider, type);
    sfVector2i tpos;
    sfVector2f pos;

    if (!edit_b || !sets)
        return ;
    tpos = edit_b->comp[find_comp(edit_b, POS)]->v2i;
    tpos.x += x_offset;
    tpos.y *= sets->size.y / slider->view_box.height;
    pos = sfRenderWindow_mapPixelToCoords(sets->window,
                                            tpos, sets->view);
    set_pos(edit_b, pos.x, pos.y);
    sfSprite_setScale(edit_b->sprite, sets->scale);
    link_view_button_function(sets, edit_b);
    draw_game_object(*sets, edit_b);
}

void draw_view_button(win_settings_t *sets, game_obj_t *slider,
                                                float x_offset)
{
    if (!sets || !slider || sets->mode.edit_mode != VIEW_MODE)
        return ;
    draw_view_button_by_type(sets, slider, x_offset, TEXTURE_VIEW_BUTTON);
    draw_view_button_by_type(sets, slider, x_offset, VERTEX_VIEW_BUTTON);
    draw_view_button_by_type(sets, slider, x_offset, PIN_VIEW_BUTTON);
}