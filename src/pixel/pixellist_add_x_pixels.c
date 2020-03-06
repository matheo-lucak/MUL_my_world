/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Adds a X nb of pixels to a pixel list
*/

#include "pixel.h"
#include "vector_engine.h"

sfBool pixellist_add_x_pixels(pixellist_t **head,
                                const sfFloatRect boundings,
                                const size_t nb_pixels)
{
    static size_t pixel_nb = 0;
    size_t index;

    pixel_nb += nb_pixels;
    if (pixel_nb > 3000)
        return (sfFalse);
    for (index = 0; index < nb_pixels; index++) {
        if (!pixellist_add_pixel(head, vec2f(
                        get_randomnb(boundings.left, boundings.width),
                        get_randomnb(boundings.top, boundings.height))))
            return (sfFalse);
        index += 1;
    }
    return (sfTrue);
}