/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Frees a pixel list
*/

#include <stdlib.h>
#include "pixel.h"

void free_pixels(pixellist_t **head)
{
    pixellist_t *tmp = NULL;
    pixellist_t *save = NULL;

    if (!(*head))
        return;
    save = (*head)->prev;
    for (tmp = (*head); tmp != save->prev; tmp = tmp->next) {
        (*head) = (*head)->next;
        if (tmp)
            free(tmp);
    }
    if (tmp)
        free(tmp);
    (*head) = NULL;
}