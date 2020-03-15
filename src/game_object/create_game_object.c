/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Creates a game_object / Finds its component.
*/

#include <stdlib.h>
#include "game_object.h"

int find_comp(game_obj_t *obj, const prop_t type)
{
    register int index = 0;

    if (!obj || !(obj->comp))
        return (0);
    while (obj->comp[index] && obj->comp[index]->type != type
        && index < obj->comp_nb)
        index += 1;
    if (obj->comp[index]->type != type)
        return (0);
    return (index);
}

game_obj_t *create_game_obj(const elem_t type)
{
    game_obj_t *obj = malloc(sizeof(game_obj_t));

    if (!obj)
        return (NULL);
    obj->next = NULL;
    obj->type = type;
    if (!init_game_object(obj))
        return (NULL);
    return (obj);
}