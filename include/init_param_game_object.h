/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** A header for the initialization part of the game objects generation
*/

#ifndef INIT_PARAM_GAME_OBJECT_H_
#define INIT_PARAM_GAME_OBJECT_H_

#include "game_object.h"

sfBool set_texture(game_obj_t *obj, char *buffer);
sfBool set_frame_nb(game_obj_t *obj, char *buffer);
sfBool set_view_box(game_obj_t *obj);
sfBool set_sprite(game_obj_t *obj);
sfBool set_origin(game_obj_t *obj, char *buffer);

static const char *params[] = {
    "texture",
    "frame_nb",
    "origin",
    NULL
};

static sfBool (*get_param_from_file[])(game_obj_t *obj, char *buffer) = {
    set_texture,
    set_frame_nb,
    set_origin
};

char **get_config_path(void);

sfBool set_all_component(game_obj_t *obj, int fd, char *buffer);

#endif /* !INIT_PARAM_GAME_OBJECT_H_ */
