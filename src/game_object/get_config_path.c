/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Gets the config path.
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_world.h"
#include "my.h"

static int get_config_path_len(int fd)
{
    char *tmp = NULL;
    int len = 0;

    tmp = get_next_line(fd);
    if (!tmp) {
        close(fd);
        return (0);
    }
    len = my_getnbr(tmp);
    if (!my_str_is_num(tmp) || len <= 0) {
        free(tmp);
        close(fd);
        return (0);
    }
    return (len);
}

static sfBool fill_config_path(char **config_path, int len, int fd)
{
    register int index = 0;

    while (index < len) {
        config_path[index] = get_next_line(fd);
        if (!config_path[index]) {
            my_free_arr(config_path);
            return (sfFalse);
        }
        index += 1;
    }
    config_path[index] = NULL;
    return (sfTrue);
}

char **get_config_path(void)
{
    char **config_path = NULL;
    int fd = open("assets/config/object_paths", O_RDONLY);
    int len = 0;

    if (fd == -1)
        return (NULL);
    len = get_config_path_len(fd);
    if (!len) {
        close(fd);
        return (NULL);
    }
    config_path = malloc(sizeof(char *) * (len + 1));
    if (!config_path || !fill_config_path(config_path, len, fd)) {
        close(fd);
        return (NULL);
    }
    close(fd);
    return (config_path);
}