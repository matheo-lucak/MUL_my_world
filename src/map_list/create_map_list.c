/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** create_map_list.c
*/

#include <stdlib.h>
#include "my_world.h"

static void add_map_node(map_linked_list_t **head,
                        const sfTexture **textures,
                        const sfShader **shaders)
{
    map_linked_list_t *node = NULL;
    map_linked_list_t *tmp = NULL;

    if (!(*head))
        return;
    node = malloc(sizeof(map_linked_list_t));
    if (!node)
        return;
    node->tile->shape_drawer = NULL;
    node->tile->rstate.blendMode = sfBlendAlpha;
    node->tile->rstate.transform = sfTransform_Identity;
    node->tile->rstate.texture = textures[0];
    node->tile->rstate.shader = shaders[0];
    for (tmp = *head; tmp->next; tmp = tmp->next);
    tmp = node;
    tmp->next = (*head);
    tmp->prev = (*head)->prev;
    (*head)->prev->next = tmp;
    (*head)->prev = tmp;
}

static void add_first_map_node(map_linked_list_t **head,
                                const sfTexture **textures,
                                const sfShader **shaders)
{
    map_linked_list_t *node = malloc(sizeof(map_linked_list_t));

    if (!node)
        return;
    node->tile->shape_drawer = NULL;
    node->tile->rstate.blendMode = sfBlendAlpha;
    node->tile->rstate.transform = sfTransform_Identity;
    node->tile->rstate.texture = textures[0];
    node->tile->rstate.shader = shaders[0];
    node->next = node;
    node->prev = node;
    (*head) = node;
}

void create_map_list(map_linked_list_t **head,
                    const sfVector2i map_limits,
                    const sfTexture **textures,
                    const sfShader **shaders)
{
    const int map_volume = map_limits.x * map_limits.y;
    int index = 0;

    while (index < map_volume) {
        if (*head)
            add_first_map_node(head, textures, shaders);
        else
            add_map_node(head, textures, shaders);
        index += 1;
    }
}