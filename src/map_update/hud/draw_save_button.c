/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_save_button
*/

#include "my_world.h"
#include "game_object.h"
#include "vector_engine.h"

static void save_button_interaction(win_settings_t *sets, game_obj_t *button)
{
    sfSound *sound = button->comp[find_comp(button, SOUND)]->sound;
    sfBool overlap = sfFalse;

    overlap = sfFloatRect_contains(&(button->hitbox), sets->mouse_tool.pos.x,
                                                    sets->mouse_tool.pos.y);
    if (overlap && sets->mouse_tool.click) {
        button->comp[find_comp(button, BOOL)]->i = 1;
        if (sound && !(sets->muted))
            sfSound_play(sound);
    }
}

static void draw_button_by_type(win_settings_t *sets, game_obj_t *button)
{
    int shift = 1;

    if (button->type == LOAD_BUTTON)
        shift = 2;
    set_pos(button, sets->anchor.bottomright.x -
                    button->view_box.width * sets->scale.x * shift,
                    sets->anchor.bottomright.y -
                    button->view_box.height * sets->scale.y);
    sfSprite_setScale(button->sprite, sets->scale);
    save_button_interaction(sets, button);
    draw_game_object(*sets, button);
}

void draw_save_button(win_settings_t *sets, game_obj_t *save_button)
{
    game_obj_t *load_button = find_game_object(save_button, LOAD_BUTTON);

    if (!sets || !save_button || !load_button)
        return ;
    draw_button_by_type(sets, save_button);
    draw_button_by_type(sets, load_button);
}