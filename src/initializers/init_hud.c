/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_hud
*/

#include "game_object.h"
#include "my_world.h"

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
    return (sfTrue);
}