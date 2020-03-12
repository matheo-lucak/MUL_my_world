/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** A header to initialize components for game objects
*/

#ifndef INIT_COMP_GAME_OBJECT_H_
#define INIT_COMP_GAME_OBJECT_H_

#include "game_object.h"

sfBool init_irect(game_obj_t *obj, char *buffer);
sfBool init_v2f(game_obj_t *obj, char *buffer);
sfBool init_v2i(game_obj_t *obj, char *buffer);
sfBool init_f(game_obj_t *obj, char *buffer);
sfBool init_i(game_obj_t *obj, char *buffer);
sfBool init_clock(game_obj_t *obj, char *buffer);
sfBool init_text(game_obj_t *obj, char *buffer);
sfBool init_sound(game_obj_t *obj, char *buffer);
sfBool init_image(game_obj_t *obj, char *buffer);

static sfBool (*init_component[])(game_obj_t *obj, char *buffer) = {
    init_clock,
    init_image,
    init_text,
    init_sound,
    init_v2i,
    init_v2f,
    init_irect,
    init_i,
    init_f
};

static char *component_pattern[] = {
    "clock",
    "image",
    "text",
    "sound",
    "v2i",
    "v2f",
    "irect",
    "int",
    "float",
    NULL
};

#endif /* !INIT_COMP_GAME_OBJECT_H_ */