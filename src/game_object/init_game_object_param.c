/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Inits parameters of a game_obj.
*/

#include "my.h"
#include "game_object.h"

sfBool set_sprite(game_obj_t *obj)
{
    if (!obj || !(obj->texture))
        return (sfFalse);
    obj->sprite = sfSprite_create();
    if (!(obj->sprite)) {
        my_printf("Set sprite failed for game_object %d\n", obj->type);
        return (sfFalse);
    }
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setTextureRect(obj->sprite, obj->view_box);
    return (sfTrue);
}

sfBool set_texture(game_obj_t *obj, char *buffer)
{
    char **parsed_buffer = NULL;

    parsed_buffer = my_str_to_word_array(buffer, " :;", 0);
    if (!parsed_buffer || !obj)
        return (sfFalse);
    if (my_arrlen((void **)parsed_buffer) != 2) {
        my_printf("Set texture failed for game_object %d\n", obj->type);
        my_free_arr(parsed_buffer);
        return (sfFalse);
    }
    obj->texture = sfTexture_createFromFile(parsed_buffer[1], NULL);
    my_free_arr(parsed_buffer);
    if (!(obj->texture)) {
        my_printf("Set texture failed for game_object %d\n", obj->type);
        return (sfFalse);
    }
    return (sfTrue);
}

sfBool set_view_box(game_obj_t *obj)
{
    sfVector2u size = (sfVector2u){0, 0};

    if (!obj || !(obj->texture) || !(obj->frame_nb))
        return (sfFalse);
    size = sfTexture_getSize(obj->texture);
    obj->view_box.left = 0;
    obj->view_box.top = 0;
    obj->view_box.width = size.x / obj->frame_nb;
    obj->view_box.height = size.y;
    return (sfTrue);
}

sfBool set_frame_nb(game_obj_t *obj, char *buffer)
{
    char **parsed_buffer = NULL;

    parsed_buffer = my_str_to_word_array(buffer, " :;", 0);
    if (!parsed_buffer || !obj)
        return (sfFalse);
    if (my_arrlen((void **)parsed_buffer) != 2) {
        my_printf("Set frame nb failed for game_object %d\n", obj->type);
        my_free_arr(parsed_buffer);
        return (sfFalse);
    }
    obj->frame_nb = my_getnbr(parsed_buffer[1]);
    my_free_arr(parsed_buffer);
    if (!(obj->frame_nb) || !set_view_box(obj) || !set_sprite(obj))
        return (sfFalse);
    return (sfTrue);
}

sfBool set_origin(game_obj_t *obj, char *buffer)
{
    char **parsed_buffer = NULL;
    sfVector2f origin = {0, 0};

    parsed_buffer = my_str_to_word_array(buffer, " :;", 0);
    if (!parsed_buffer || !obj || !(obj->sprite))
        return (sfFalse);
    if (my_arrlen((void **)parsed_buffer) != 3) {
        my_printf("Set frame nb failed for game_object %d\n", obj->type);
        my_free_arr(parsed_buffer);
        return (sfFalse);
    }
    origin.x = my_getnbr(parsed_buffer[1]);
    origin.y = my_getnbr(parsed_buffer[2]);
    sfSprite_setOrigin(obj->sprite, origin);
    my_free_arr(parsed_buffer);
    return (sfTrue);
}