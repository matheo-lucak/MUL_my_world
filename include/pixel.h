/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** A header for pixel lists implementation
*/

#ifndef PIXEL_H_
#define PIXEL_H_

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "my_world.h"

typedef struct pixellist_s {
    sfVector2f pos;
    sfVector2f vel;
    sfVector2f acc;
    struct pixellist_s *next;
    struct pixellist_s *prev;
} pixellist_t;


//Adds a pixel to the pixel list given as parameter
//Returns False in case of error
//Returns True in case of success
sfBool pixellist_add_pixel(pixellist_t **head, const sfVector2f spawnpoint);

//Adds a pixel to the pixel list given as parameter
//Returns False in case of error
//Returns True in case of success
sfBool pixellist_add_x_pixels(pixellist_t **head, const sfVector2f spawnpoint,
                            const size_t nb_pixels);

//Updates pixel's physic such as
// Forces (Gravity, friction, traction ...)
// Inertie and mouvement
// Position
void update_pixel_physic(win_settings_t sets, pixellist_t *pixel);


//Updates all pixels in a given pixellist by:
//Updating physic
//Drawing pixel
void update_pixellist(win_settings_t sets, pixellist_t *pixels,
                                sfRectangleShape *rect);
#endif /* !PIXEL_H_ */