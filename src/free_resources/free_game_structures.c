/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Frees game structures.
*/

#include "my_world.h"

void free_game_structures(map_formatter_t *ter,  hud_t *hud)
{
    if (ter) {
        free_terraformer(ter);
    }
    if (hud) {
        free_resources_fps(&(hud->fps_assets));
        free_obj_list(hud->save_button);
        free_obj_list(hud->slider);
        free_obj_list(hud->sound_button);
        free_obj_list(hud->text_box);
    }
}