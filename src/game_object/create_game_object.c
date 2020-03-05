/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** create_game_object
*/

#include <stdlib.h>
#include "game_object.h"

int find_comp(game_obj_t *obj, prop_t type)
{
    int i = 0;

    while (obj->comp[i]->type != type && i < obj->comp_nb)
        i++;
    if (obj->comp[i]->type != type)
        return (0);
    return (i);
}

game_obj_t *create_game_obj(elem_t type)
{
    game_obj_t *obj = malloc(sizeof(game_obj_t));

    if (obj == NULL)
        return (NULL);
    obj->next = NULL;
    obj->type = type;
    if (!init_game_object(obj))
        return (NULL);
    return (obj);
}