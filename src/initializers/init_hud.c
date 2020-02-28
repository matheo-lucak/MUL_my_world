/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Initializes the HUD.
*/

#include "my_world.h"
#include "game_object.h"

static sfBool init_slider(game_obj_t **slider)
{
    if (!slider)
        return (sfFalse);
    *slider = create_game_obj(SLIDER);
    if (!(*slider))
        return (sfFalse);
    if (!add_game_obj_to_list(slider, EDIT_MODE_BUTTON)
        || !add_game_obj_to_list(slider, TEXTURE_MODE_BUTTON)
        || !add_game_obj_to_list(slider, VIEW_MODE_BUTTON)
        || !add_game_obj_to_list(slider, SLIDER_ARROW)
        || !add_game_obj_to_list(slider, TEXTURE_VIEW_BUTTON)
        || !add_game_obj_to_list(slider, VERTEX_VIEW_BUTTON)
        || !add_game_obj_to_list(slider, PIN_VIEW_BUTTON)
        || !add_game_obj_to_list(slider, TEXTURE_BAR)
        || !add_game_obj_to_list(slider, PIXEL_BUTTON)
        || !add_game_obj_to_list(slider, SPATULA_BUTTON))
        return (sfFalse);
    return (sfTrue);
}

static sfBool init_save_button(game_obj_t **save_button)
{
    if (!save_button)
        return (sfFalse);
    *save_button = create_game_obj(SAVE_BUTTON);
    if (!(*save_button))
        return (sfFalse);
    if (!add_game_obj_to_list(save_button, LOAD_BUTTON))
        return (sfFalse);
    return (sfTrue);
}

sfBool init_hud(hud_t *hud)
{
    if (!hud)
        return (sfFalse);
    if (!init_resources_fps(&(hud->fps_assets)))
        return (sfFalse);
    if (!init_slider(&(hud->slider)))
        return (sfFalse);
    if (!init_save_button(&(hud->save_button)))
        return (sfFalse);
    hud->text_box = create_game_obj(TEXT_BOX);
    hud->sound_button = create_game_obj(SOUND_BUTTON);
    hud->florian = create_game_obj(FLORIAN);
    if (!(hud->text_box) || !(hud->sound_button) || !(hud->florian))
        return (sfFalse);
    return (sfTrue);
}