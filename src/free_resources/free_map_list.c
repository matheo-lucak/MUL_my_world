/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** free_map_list.c
*/

#include <stdlib.h>
#include "my_world.h"

static void free_map_node(map_linked_list_t **node)
{
    if (!(*node))
        return;
    if ((*node)->tile->shape_drawer)
        sfVertexArray_destroy((*node)->tile->shape_drawer);
    if (*node)
        free(*node);
}

void free_map_list(map_linked_list_t **head)
{
    map_linked_list_t *tmp = NULL;
    map_linked_list_t *end = NULL;

    if (!(*head))
        return;
    end = (*head)->prev;
    for (tmp = (*head); tmp && tmp != end; tmp = *head) {
        *head = (*head)->next;
        free_map_node(&tmp);
    }
    free_map_node(&tmp);
}