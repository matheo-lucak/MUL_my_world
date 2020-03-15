/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Inits advanced comps.
*/

#include <stdlib.h>
#include "my.h"
#include "game_object.h"

sfBool init_clock(game_obj_t *obj, char *buffer)
{
    prop_t prop = my_getnbr(buffer);

    if (buffer)
        free(buffer);
    if (!prop)
        return (sfFalse);
    return (set_comp_clock(obj, prop));
}

sfBool init_text(game_obj_t *obj, char *buffer)
{
    prop_t prop = my_getnbr(buffer);
    char **parsed_buffer = my_str_to_word_array(buffer, " :;", 1);
    sfBool error = sfFalse;
    int size = 0;

    if (!parsed_buffer || !prop || my_arrlen((void **)parsed_buffer) != 4)
        return (sfFalse);
    size = my_getnbr(parsed_buffer[3]);
    if (!size) {
        my_free_arr(parsed_buffer);
        return (sfFalse);
    }
    error = set_comp_text(obj, prop, parsed_buffer[2], size);
    my_free_arr(parsed_buffer);
    return (error);
}

sfBool init_sound(game_obj_t *obj, char *buffer)
{
    prop_t prop = my_getnbr(buffer);
    char **parsed_buffer = my_str_to_word_array(buffer, " :;", 1);
    sfBool error = sfFalse;
    int volume = 0;

    if (!parsed_buffer || !prop || my_arrlen((void **)parsed_buffer) != 4)
        return (sfFalse);
    volume = my_getnbr(parsed_buffer[3]);
    if (!volume) {
        my_free_arr(parsed_buffer);
        return (sfFalse);
    }
    error = set_comp_sound(obj, prop, parsed_buffer[2], volume);
    my_free_arr(parsed_buffer);
    return (error);
}

sfBool init_image(game_obj_t *obj, char *buffer)
{
    prop_t prop = my_getnbr(buffer);
    char **parsed_buffer = my_str_to_word_array(buffer, " :;", 1);
    sfBool error = sfFalse;

    if (!parsed_buffer || !prop || my_arrlen((void **)parsed_buffer) != 3)
        return (sfFalse);
    error = set_comp_image(obj, prop, parsed_buffer[2]);
    my_free_arr(parsed_buffer);
    return (error);
}