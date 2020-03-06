/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Frees a pixel list
*/

#include <stdlib.h>
#include "pixel.h"

void free_pixels(pixellist_t *head)
{
    pixellist_t *tmp = head;

    if (!head)
        return;
    do {
        head = head->next;
        if (tmp)
            free(tmp);
        tmp = head;
    } while (tmp);
}