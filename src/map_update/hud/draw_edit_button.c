/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_edit_button
*/

#include "my_world.h"
#include "game_object.h"
#include "vector_engine.h"

static pixe_mode_flag_t find_edit_mode_from_button_type(const elem_t type)
{
    static const pixe_mode_flag_t mode_pattern[] = {PIXEL_DRAW,
                                                SPATULA_DRAW,
                                                0};
    static const elem_t type_pattern[] = {PIXEL_BUTTON,
                                            SPATULA_BUTTON, 0};
    int index = 0;

    while (type_pattern[index]) {
        if (type_pattern[index] == type)
            return (mode_pattern[index]);
        index += 1;
    }
    return (0);
}


static void link_edit_button_function(win_settings_t *sets, game_obj_t *edit_b)
{
    sfFloatRect hitbox = {0, 0, 0, 0};
    sfBool overlap = 0;
    pixe_mode_flag_t mode = find_edit_mode_from_button_type(edit_b->type);
    sfSound *sound = NULL;

    if (!sets || !edit_b || sets->paused)
        return;
    hitbox = sfSprite_getGlobalBounds(edit_b->sprite);
    overlap = sfFloatRect_contains(&hitbox, sets->mouse_tool.pos.x,
                                                    sets->mouse_tool.pos.y);
    if (overlap && sets->mouse_tool.click) {
        sound = edit_b->comp[find_comp(edit_b, SOUND)]->sound;
        if (sound && !(sets->muted))
            sfSound_play(sound);
        sets->mode.draw_mode = mode;
    }
}

static void draw_edit_button_by_type(win_settings_t *sets,
                                        game_obj_t *slider,
                                        const float x_offset,
                                        const elem_t type)
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
    link_edit_button_function(sets, edit_b);
    draw_game_object(*sets, edit_b);
}

void draw_edit_button(win_settings_t *sets, game_obj_t *slider,
                                            const float x_offset)
{
    if (!sets || !slider || sets->mode.edit_mode != PIXEL_MODE)
        return ;
    draw_edit_button_by_type(sets, slider, x_offset, PIXEL_BUTTON);
    draw_edit_button_by_type(sets, slider, x_offset, SPATULA_BUTTON);
}