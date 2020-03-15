/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_sound_button
*/

#include "my_world.h"
#include "game_object.h"
#include "vector_engine.h"

static void mute_sound_button(win_settings_t *sets, game_obj_t *sound_button)
{
    sfSound *sound = NULL;
    sfBool overlap = sfFalse;

    overlap = sfFloatRect_contains(&(sound_button->hitbox),
                                    sets->mouse_tool.pos.x,
                                    sets->mouse_tool.pos.y);
    if (sets->mouse_tool.click && overlap) {
        sound = sound_button->comp[find_comp(sound_button, SOUND)]->sound;
        if (sound && !(sets->muted))
            sfSound_play(sound);
        if (!(sets->muted)) {
            sets->muted = 1;
            set_game_object_frame(sound_button, 1);
        } else {
            sets->muted = 0;
            set_game_object_frame(sound_button, 0);
        }
    }
}

void draw_sound_button(win_settings_t *sets, game_obj_t *sound_button)
{

    set_pos(sound_button, sets->anchor.topright.x -
            sound_button->view_box.width * sets->scale.x,
            sets->anchor.topright.y +
            sound_button->view_box.height * sets->scale.y);
    sfSprite_setScale(sound_button->sprite, sets->scale);
    mute_sound_button(sets, sound_button);
    draw_game_object(*sets, sound_button);
}