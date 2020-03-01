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
    PLAYER2,
    BACKGROUND,
    MIDDLEGROUND,
    GROUND,
    HOUSE,
    BARREL,
    HEALTH_BAR,
    STAMINA_BAR,
    CRATE,
    HAY_WAGON,
    WELL,
    CURSOR,
    MAP_NAME_FIELD,
    WOOD_T,
    WOOD_B,
    WOOD_L,
    WOOD_R,
    SPIKE,
    ITEM_BAR,
    B_PLAY,
    B_INF_PLAY,
    B_EDIT,
    SCORE_BAR,
    HSCORE_BAR,
    NONE
} elem_t;

typedef enum prop
{
    LIFE,
    STAMINA,
    SPEED,
    GRAVITY,
    FALL_SPEED,
    JUMP_SPEED,
    CLOCK,
    JUMP_CLOCK,
    IMAGE,
    DEFAULT_IMAGE,
    FALLING,
    JUMPING,
    RUNNING,
    BLOCKED,
    NORMAL_HITBOX,
    JUMP_HITBOX,
    BAR_FIELD,
    ORIGIN,
    TEXT,
    JUMP_SOUND,
    HIT_SOUND,
    HIT_SOUND2,
    SAVED_X
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
