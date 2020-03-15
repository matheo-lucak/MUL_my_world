/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Finds a game_obj.
*/

#include "game_object.h"

game_obj_t *find_game_object(game_obj_t *list, elem_t type)
{
    game_obj_t *tmp = list;

    while (tmp && tmp->type != type)
        tmp = tmp->next;
    return (tmp);
}