/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Adds a X nb of pixels to a pixel list
*/

#include "pixel.h"

sfBool pixellist_add_x_pixels(pixellist_t **head,
                            const sfVector2f spawnpoint,
                            const size_t nb_pixels)
{
    register size_t index = 0;

    while (index < nb_pixels) {
        if (!pixellist_add_pixel(head, spawnpoint))
            return (sfFalse);
        index += 1;
    }
    return (sfTrue);
}