/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_mode_button
*/

#include "my_world.h"
#include "game_object.h"
#include "vector_engine.h"

static edit_mode_flag_t find_game_mode_from_button_type(const elem_t type)
{
    static const edit_mode_flag_t mode_pattern[] = {VIEW_MODE,
                                                    TEXTURE_MODE,
                                                    PIXEL_MODE, 0};
    static const elem_t type_pattern[] = {VIEW_MODE_BUTTON,
                                        TEXTURE_MODE_BUTTON,
                                        EDIT_MODE_BUTTON,
                                        0};
    int index = 0;

    while (type_pattern[index]) {
        if (type_pattern[index] == type)
            return (mode_pattern[index]);
        index += 1;
    }
    return (0);
}

static void link_button_function(win_settings_t *sets, game_obj_t *edit_b)
{
    sfFloatRect hitbox = {0, 0, 0, 0};
    sfBool overlap = 0;
    sfSound *sound = NULL;
    edit_mode_flag_t mode = 0;

    if (!sets || !edit_b || sets->paused)
        return ;
    hitbox = sfSprite_getGlobalBounds(edit_b->sprite);
    overlap = sfFloatRect_contains(&hitbox, sets->mouse_tool.pos.x,
                                            sets->mouse_tool.pos.y);
    if (sets->mouse_tool.click && overlap) {
        mode = find_game_mode_from_button_type(edit_b->type);
        if (mode != sets->mode.edit_mode)
            change_edit_mode(&(sets->mode), mode);
        sound = edit_b->comp[find_comp(edit_b, SOUND)]->sound;
        if (sound && !(sets->muted)) {
            sfSound_play(sound);
        }
    }
}

static void draw_slider_button_by_type(win_settings_t *sets,
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
    link_button_function(sets, edit_b);
    draw_game_object(*sets, edit_b);
}

void draw_slider_button(win_settings_t *sets, map_formatter_t ter,
                        game_obj_t *slider, const float x_offset)
{
    draw_slider_button_by_type(sets, slider, x_offset,
                                            EDIT_MODE_BUTTON);
    draw_slider_button_by_type(sets, slider, x_offset,
                                            TEXTURE_MODE_BUTTON);
    draw_slider_button_by_type(sets, slider, x_offset,
                                            VIEW_MODE_BUTTON);
    draw_view_button(sets, slider, x_offset);
    draw_texture_bar(sets, ter, slider, x_offset);
    draw_edit_button(sets, slider, x_offset);
}