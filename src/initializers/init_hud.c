/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_hud
*/

#include "my_world.h"
#include "game_object.h"

sfBool init_hud(hud_t *hud)
{
    if (!hud)
        return (sfFalse);
    if (!init_resources_fps(&(hud->fps_assets)))
        return (sfFalse);
    hud->slider = create_game_obj(SLIDER);
    hud->texture_bar = create_game_obj(TEXTURE_BAR);
    if (!(hud->slider) || !(hud->texture_bar)) {
        free_obj(hud->slider);
        free_obj(hud->texture_bar);
        return (sfFalse);
    }
    add_game_obj_to_list(&(hud->slider), EDIT_MODE_BUTTON);
    add_game_obj_to_list(&(hud->slider), TEXTURE_MODE_BUTTON);
    add_game_obj_to_list(&(hud->slider), VIEW_MODE_BUTTON);
    add_game_obj_to_list(&(hud->slider), SLIDER_ARROW);
    add_game_obj_to_list(&(hud->slider), TEXTURE_VIEW_BUTTON);
    add_game_obj_to_list(&(hud->slider), VERTEX_VIEW_BUTTON);
    add_game_obj_to_list(&(hud->slider), PIN_VIEW_BUTTON);
    add_game_obj_to_list(&(hud->slider), TEXTURE_BAR);
    return (sfTrue);
}