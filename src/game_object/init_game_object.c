/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_game_object
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "init_param_game_object.h"
#include "my.h"

static sfBool (*get_param_from_file[])(game_obj_t *obj, char *buffer);

static const char *params[];

static const char *config_path[];

int find_param(char *buffer)
{
    int index = 0;

    while (params[index]) {
        if (my_hay_needle(buffer, params[index]) != -1)
            return (index);
        index += 1;
    }
    return (-1);
}

sfBool init_game_object(game_obj_t *obj)
{
    char *buffer = NULL;
    int fd = open(config_path[obj->type], O_RDONLY);
    int param_index = -1;

    do {
        buffer = get_next_line(fd);
        param_index = find_param(buffer);
        if (buffer && param_index != -1 &&
            !get_param_from_file[param_index](obj, buffer))
            return (sfFalse);
    } while (buffer && my_hay_needle(buffer, "component : ") == -1);
    if (!(obj->texture))
        return (sfFalse);
    obj->pos = (sfVector2f){0, 0};
    set_view_box(obj);
    set_hitbox(obj);
    set_all_component(obj, fd, buffer);
    close(fd);
    return (sfTrue);
}