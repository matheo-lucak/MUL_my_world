/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** my_skip_a_file_line.c
*/

#include <stdlib.h>
#include "my.h"

int my_skip_a_file_line(const int fd)
{
    char *line = NULL;

    line = get_next_line(fd);
    if (line) {
        free(line);
        return (1);
    }
    return (0);
}