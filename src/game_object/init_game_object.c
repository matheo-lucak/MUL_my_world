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

sfBool fill_basic_game_object(game_obj_t *obj, int fd, char *buffer)
{
    if (!obj)
        return (sfFalse);
    if (!(obj->texture))
        return (sfFalse);
    obj->pos = (sfVector2f){0, 0};
    if (!set_view_box(obj) || !set_all_component(obj, fd, buffer))
        return (sfFalse);
    set_hitbox(obj);
    if (fd != -1)
        close(fd);
    return (sfTrue);
}

sfBool init_game_object(game_obj_t *obj)
{
    static char **config_path = NULL;
    char *buffer = NULL;
    int param_index = -1;
    int fd = 0;

    if (!config_path)
        config_path = get_config_path();
    if (config_path) {
        fd = open(config_path[obj->type], O_RDONLY);
    }
    do {
        buffer = get_next_line(fd);
        param_index = find_param(buffer);
        if (buffer && param_index != -1 &&
            !get_param_from_file[param_index](obj, buffer))
            return (sfFalse);
    } while (buffer && my_hay_needle(buffer, "component : ") == -1);
    return (fill_basic_game_object(obj, fd, buffer));
}