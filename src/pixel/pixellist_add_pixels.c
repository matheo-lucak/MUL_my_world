/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** pixelList_addPixelToPixelList
*/

#include <stdlib.h>
#include "my_world.h"
#include "pixel.h"

static sfBool pixellist_add_new_pixel(pixellist_t **head,
                                        const sfVector2f spawning_position)
{
    pixellist_t *node = malloc(sizeof(pixellist_t));

    if (!node)
        return (sfFalse);
    node->pos = spawning_position;
    node->vel = (sfVector2f){get_randomnb(-2, 2), get_randomnb(-2, 2)};
    node->acc = (sfVector2f){0, 0};
    node->next = (*head);
    node->prev = (*head)->prev;
    (*head)->prev->next = node;
    (*head)->prev = node;
    return (sfTrue);
}

static sfBool pixellist_add_first_pixel(pixellist_t **head,
                                            const sfVector2f spawning_position)
{
    *head = malloc(sizeof(pixellist_t));
    if (!(*head))
        return (sfFalse);
    (*head)->pos = spawning_position;
    (*head)->vel = (sfVector2f){get_randomnb(-2, 2), get_randomnb(-2, 2)};
    (*head)->acc = (sfVector2f){0, 0};
    (*head)->next = *head;
    (*head)->prev = *head;
    return (sfTrue);
}

sfBool pixellist_add_pixel(pixellist_t **head,
                            const sfVector2f spawning_position)
{
    if (!(*head) && !pixellist_add_first_pixel(head, spawning_position)) {
        return (sfFalse);
    } else if (!pixellist_add_new_pixel(head, spawning_position)) {
        return (sfFalse);
    }
    return (sfTrue);
}