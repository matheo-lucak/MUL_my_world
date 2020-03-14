/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** set_game_object_param
*/

#include "game_object.h"

void set_pos(game_obj_t *obj, float x, float y)
{
    obj->pos.x = x;
    obj->pos.y = y;
    obj->hitbox = sfSprite_getGlobalBounds(obj->sprite);
}

void set_hitbox(game_obj_t *obj)
{
    obj->hitbox.left = obj->pos.x;
    obj->hitbox.top = obj->pos.y;
    obj->hitbox.width = obj->view_box.width;
    obj->hitbox.height = obj->view_box.height;
}