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
    EARTH,
    NONE
} elem_t;

typedef enum prop
{
    LIFE
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
    sfIntRect view_box;
    sfFloatRect hitbox;
    sfVector2f pos;
    unsigned int frame_nb;
    int comp_nb;
    elem_t type;
} game_obj_t;


game_obj_t *create_game_obj(elem_t type);

int find_comp(game_obj_t *obj, prop_t type);

sfBool init_game_object(game_obj_t *obj);

void set_hitbox(game_obj_t *obj);
void set_pos(game_obj_t *obj, float x, float y);

component_t *add_comp(game_obj_t *obj, prop_t type);

sfBool set_comp_int(game_obj_t *obj, prop_t type, int nb);
sfBool set_comp_float(game_obj_t *obj, prop_t type, float nb);
sfBool set_comp_v2i(game_obj_t *obj, prop_t type, sfVector2i vec);
sfBool set_comp_v2f(game_obj_t *obj, prop_t type, sfVector2f vec);

sfBool set_comp_sound(game_obj_t *obj, prop_t type, char *path, float volume);
sfBool set_comp_text(game_obj_t *obj, prop_t type, char *path, int size);
sfBool set_comp_image(game_obj_t *obj, prop_t type, char *path);
sfBool reset_comp_clock(game_obj_t *obj, prop_t type);
sfBool set_comp_clock(game_obj_t *obj, prop_t type);



#endif /* !GAME_OBJECT_H_ */
