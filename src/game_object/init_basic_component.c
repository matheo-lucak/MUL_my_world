/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Inits basic comps.
*/

#include "my.h"
#include "game_object.h"

sfBool init_irect(game_obj_t *obj, char *buffer)
{
    prop_t prop = my_getnbr(buffer);
    char **parsed_input = my_str_to_word_array(buffer, " :;", 1);
    sfBool error = sfFalse;

    if (!parsed_input || !prop || my_arrlen((void **)parsed_input) != 6)
        return (sfFalse);
    error = set_comp_irect(obj, prop, (sfIntRect)
                        {my_getnbr(parsed_input[2]),
                        my_getnbr(parsed_input[3]),
                        my_getnbr(parsed_input[4]),
                        my_getnbr(parsed_input[5])});
    my_free_arr(parsed_input);
    return (error);
}

sfBool init_v2f(game_obj_t *obj, char *buffer)
{
    prop_t prop = my_getnbr(buffer);
    char **parsed_input = my_str_to_word_array(buffer, " :;", 1);
    sfBool error = sfFalse;

    if (!parsed_input || !prop || my_arrlen((void **)parsed_input) != 4)
        return (sfFalse);
    error = set_comp_v2f(obj, prop, (sfVector2f)
                                    {(float)my_getnbr(parsed_input[2]),
                                    (float)my_getnbr(parsed_input[3])});
    my_free_arr(parsed_input);
    return (error);
}

sfBool init_v2i(game_obj_t *obj, char *buffer)
{
    prop_t prop = my_getnbr(buffer);
    char **parsed_input = my_str_to_word_array(buffer, " :;", 1);
    sfBool error = sfFalse;

    if (!parsed_input || !prop || my_arrlen((void **)parsed_input) != 4)
        return (sfFalse);
    error = set_comp_v2i(obj, prop, (sfVector2i){my_getnbr(parsed_input[2]),
                                                my_getnbr(parsed_input[3])});
    my_free_arr(parsed_input);
    return (error);
}

sfBool init_f(game_obj_t *obj, char *buffer)
{
    prop_t prop = my_getnbr(buffer);
    char **parsed_input = my_str_to_word_array(buffer, " :;", 1);
    sfBool error = sfFalse;

    if (!parsed_input || !prop || my_arrlen((void **)parsed_input) != 3)
        return (sfFalse);
    error = set_comp_float(obj, prop, (float)my_getnbr(parsed_input[2]));
    my_free_arr(parsed_input);
    return (error);
}

sfBool init_i(game_obj_t *obj, char *buffer)
{
    prop_t prop = my_getnbr(buffer);
    char **parsed_input = my_str_to_word_array(buffer, " :;", 1);
    sfBool error = sfFalse;

    if (!parsed_input || !prop || my_arrlen((void **)parsed_input) != 3)
        return (sfFalse);
    error = set_comp_int(obj, prop, my_getnbr(parsed_input[2]));
    my_free_arr(parsed_input);
    return (error);
}