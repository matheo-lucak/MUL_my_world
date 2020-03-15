/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** A header for game objects.
*/

#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include "SFML/Audio.h"
#include "SFML/Window.h"
#include "SFML/System.h"
#include "SFML/Graphics.h"

typedef enum element_e {
    EARTH,
    BACKGROUND_SPACE,
    SLIDER,
    TEXTURE_BAR,
    TEXTURE_VIEW_BUTTON,
    VERTEX_VIEW_BUTTON,
    PIN_VIEW_BUTTON,
    SLIDER_ARROW,
    EDIT_MODE_BUTTON,
    TEXTURE_MODE_BUTTON,
    VIEW_MODE_BUTTON,
    SAVE_BUTTON,
    LOAD_BUTTON,
    TEXT_BOX,
    SOUND_BUTTON,
    PIXEL_BUTTON,
    SPATULA_BUTTON,
    NONE
} elem_t;

typedef enum properties_e {
    SOUND = 1,
    CLOCK,
    OFFSET,
    SHIFT,
    POS,
    TEXT,
    BOOL,
    SIZE
} prop_t;

typedef struct component_s {
    prop_t type;
    sfClock *clock;
    sfImage *image;
    sfText *text;
    sfSound *sound;
    sfVector2i v2i;
    sfVector2f v2f;
    sfIntRect irect;
    int i;
    float f;
} component_t;

typedef struct game_obj {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect view_box;
    sfFloatRect hitbox;
    sfVector2f pos;
    unsigned int frame_nb;
    int comp_nb;
    elem_t type;
    component_t **comp;
    struct game_obj *next;
} game_obj_t;

//Initializes a game_object considering its type.
//
//Returns a pointer towards the game_object if it was correctly initialized.
//Returns a NULL pointer otherwise.
game_obj_t *create_game_obj(const elem_t type);

//Entirely frees a game_object.
//
//Returns sfTrue if the given pointer isn't NULL.
//Returns sfFalse otherwise.
sfBool free_obj(game_obj_t *obj);

//Frees the components of a game_object (clock, images ...).
//
//Returns sfTrue if the given pointer isn't NULL.
//Returns sfFalse otherwise.
sfBool free_all_comp(game_obj_t *obj);

//Adds a new uninitialized game_object to a game_object linked list.
//
//Returns sfTrue if the operation was a success.
//Returns sfFalse otherwise.
sfBool add_game_obj_to_list(game_obj_t **list, const elem_t element);

//Returns a pointer towards a looked-for game_object in a game_object linked
//list.
//
//Returns a pointer towards the game_object if it has been found.
//Returns a NULL pointer otherwise.
game_obj_t *find_game_object(game_obj_t *list, const elem_t type);

int find_comp(game_obj_t *obj, prop_t type);

sfBool init_game_object(game_obj_t *obj);

void set_game_object_frame(game_obj_t *obj, unsigned int frame);

void anime_game_object(game_obj_t *obj, const int lapse);

sfBool set_origin(game_obj_t *obj, char *buffer);
void set_hitbox(game_obj_t *obj);
void set_pos(game_obj_t *obj, float x, float y);

component_t *add_comp(game_obj_t *obj, prop_t type);

sfBool set_comp_int(game_obj_t *obj, prop_t type, int nb);
sfBool set_comp_float(game_obj_t *obj, prop_t type, float nb);
sfBool set_comp_v2i(game_obj_t *obj, prop_t type, sfVector2i vec);
sfBool set_comp_v2f(game_obj_t *obj, prop_t type, sfVector2f vec);
sfBool set_comp_irect(game_obj_t *obj, prop_t type, sfIntRect rect);

sfBool set_comp_sound(game_obj_t *obj, prop_t type, char *path, float volume);
sfBool set_comp_text(game_obj_t *obj, prop_t type, char *path, int size);
sfBool set_comp_image(game_obj_t *obj, prop_t type, char *path);
sfBool reset_comp_clock(game_obj_t *obj, prop_t type);
sfBool set_comp_clock(game_obj_t *obj, prop_t type);

#endif /* !GAME_OBJECT_H_ */