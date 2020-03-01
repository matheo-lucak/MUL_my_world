/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** pixellist_add_pixel
*/

#include "pixel.h"

sfBool pixellist_add_x_pixels(pixellist_t **head,
                                const sfVector2f spawning_position,
                                const size_t nb_pixels)
{
    size_t index;

    for (index = 0; index < nb_pixels; index++) {
        if (!pixellist_add_pixel(head, spawning_position))
            return (sfFalse);
    }
    return (sfTrue);
}