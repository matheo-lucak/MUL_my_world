/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_game_object
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "game_object.h"
#include "my.h"

static const char *config_path[] =
{
    "assets/config/objects/earth"
};

static sfBool get_texture(int fd, sfTexture **texture)
{
    char **parsed_buffer = NULL;

    parsed_buffer = my_str_to_word_array(get_next_line(fd), " :;", 1);
    if (!parsed_buffer || !texture ||
        my_strncmp(parsed_buffer[0], "texture", 7))
        return (sfFalse);
    if (my_arrlen((void **)parsed_buffer) != 2) {
        my_free_arr(parsed_buffer);
        return (sfFalse);
    }
    *texture = sfTexture_createFromFile(parsed_buffer[1], NULL);
    my_free_arr(parsed_buffer);
    if (!(*texture))
        return (sfFalse);
    return (sfTrue);
}

static sfBool get_frame_nb(int fd, unsigned int *frame_nb)
{
    char **parsed_buffer = NULL;

    parsed_buffer = my_str_to_word_array(get_next_line(fd), " :;", 1);
    if (!parsed_buffer || !frame_nb ||
        my_strncmp(parsed_buffer[0], "frame_nb", 8))
        return (sfFalse);
    if (my_arrlen((void **)parsed_buffer) != 2) {
        my_free_arr(parsed_buffer);
        return (sfFalse);
    }
    *frame_nb = my_getnbr(parsed_buffer[1]);
    my_free_arr(parsed_buffer);
    if (!(*frame_nb))
        return (sfFalse);
    return (sfTrue);
}

static sfBool get_view_box(sfTexture *texture, sfIntRect *view_box,
                                                        int frame_nb)
{
    sfVector2u size = (sfVector2u){0, 0};

    if (!view_box || !texture)
        return (sfFalse);
    size = sfTexture_getSize(texture);
    view_box->left = 0;
    view_box->top = 0;
    view_box->width = size.x / frame_nb;
    view_box->height = size.y;
    return (sfTrue);
}

static sfBool set_sprite(sfSprite **sprite, sfTexture *texture)
{
    if (sprite || texture)
        return (sfFalse);
    *sprite = sfSprite_create();
    if (!(*sprite))
        return (sfFalse);
    sfSprite_setTexture(*sprite, texture, sfFalse);
    return (sfTrue);
}

sfBool init_game_object(game_obj_t *obj)
{
    int fd = open(config_path[obj->type], O_RDONLY);

    if (fd == -1)
        return (sfFalse);
    if (!get_texture(fd, &(obj->texture))) {
        my_putstr("Bad Texture config file\n");
        return (sfFalse);
    }
    if (!get_frame_nb(fd, &(obj->frame_nb))){
        my_putstr("Bad Frame config file\n");
        return (sfFalse);
    }
    if (!get_view_box(obj->texture, &(obj->view_box), obj->frame_nb) ||
        !set_sprite(&(obj->sprite), obj->texture))
        return (sfFalse);
    obj->pos = (sfVector2f){0, 0};
    set_hitbox(obj);
    close(fd);
    return (sfTrue);
}