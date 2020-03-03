/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** widget
*/

#ifndef WIDGET_H_
#define WIDGET_H_

#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>

typedef enum button_state_s
{
    IDLE,
    HOVER,
    CLICKED
} button_state_s;

typedef struct widget_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
    sfIntRect local_rect;
    sfVector2f pos;
    void *type;
} widget_t;

typedef struct button_s
{
    sfText *text;
    sfFont *font;
    void *func(void *, void *);
} button_t;

#endif /* !WIDGET_H_ */
