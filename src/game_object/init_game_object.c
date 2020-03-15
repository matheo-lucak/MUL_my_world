/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Inits a game_obj.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "init_param_game_object.h"
#include "my.h"

static sfBool (*get_param_from_file[])(game_obj_t *obj, char *buffer);

static const char *params[];

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
    set_hitbox(obj);
    set_all_component(obj, fd, buffer);
    if (fd != -1)
        close(fd);
    return (sfTrue);
}

sfBool read_config_file(int fd, game_obj_t *obj)
{
    char *buffer = NULL;
    int param_index = -1;

    do {
        if (buffer) {
            free(buffer);
            buffer = NULL;
        }
        buffer = get_next_line(fd);
        param_index = find_param(buffer);
        if (buffer && param_index != -1 &&
            !get_param_from_file[param_index](obj, buffer))
            return (sfFalse);
    } while (buffer && my_hay_needle(buffer, "component : ") == -1);
    return (fill_basic_game_object(obj, fd, buffer));
}

sfBool init_game_object(game_obj_t *obj)
{
    static char **config_path = NULL;
    int fd = 0;

    if (!config_path)
        config_path = get_config_path();
    if (config_path) {
        if ((int)obj->type > my_arrlen((void **)config_path))
            return (sfFalse);
        fd = open(config_path[obj->type], O_RDONLY);
    }
    return (read_config_file(fd, obj));
}