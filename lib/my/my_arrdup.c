/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** duplicates an array
*/

#include <stdlib.h>
#include "my.h"

char **my_arrdup(const char * const *template)
{
    char **dup = NULL;
    int size = my_arrlen((char **)template);
    int index = 0;

    if (size == -1)
        return (NULL);
    dup = malloc(sizeof(char *) * (size + 1));
    if (!dup)
        return (NULL);
    dup[size] = NULL;
    while (template[index]) {
        dup[index] = my_strdup(template[index]);
        index += 1;
    }
    return (dup);
}