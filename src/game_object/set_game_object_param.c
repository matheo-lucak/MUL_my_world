/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Sets the parameters of a game_obj
*/

#include "game_object.h"

void set_pos(game_obj_t *obj, float x, float y)
{
    obj->pos.x = x;
    obj->pos.y = y;
    sfSprite_setPosition(obj->sprite, obj->pos);
    obj->hitbox = sfSprite_getGlobalBounds(obj->sprite);
}

void set_hitbox(game_obj_t *obj)
{
    obj->hitbox.left = obj->pos.x;
    obj->hitbox.top = obj->pos.y;
    obj->hitbox.width = obj->view_box.width;
    obj->hitbox.height = obj->view_box.height;
}