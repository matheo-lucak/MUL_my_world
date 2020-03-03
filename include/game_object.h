/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** game_object
*/

#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include "SFML/Audio.h"
#include "SFML/Window.h"
#include "SFML/System.h"
#include "SFML/Graphics.h"

typedef enum elem
{
    PLAYER,
    NONE
} elem_t;

typedef enum prop
{
    LIFE,
} prop_t;

typedef struct component
{
    sfClock *clock;
    sfImage *image;
    sfText *text;
    sfSound *sound;
    prop_t type;
    sfVector2i v2i;
    sfVector2f v2f;
    sfIntRect irect;
    int i;
    float f;
} component_t;

typedef struct game_obj
{
    component_t **comp;
    sfTexture *texture;
    sfSprite *sprite;
    struct game_obj *next;
    sfVector2f pos;
    sfIntRect l_rect;
    sfFloatRect g_rect;
    int comp_nb;
    elem_t type;
} game_obj_t;

#endif /* !GAME_OBJECT_H_ */
