/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** appends a string to an array
*/

#include <stdlib.h>
#include "my.h"

static void free_assets(char **array, char **str)
{
    my_free_arr(array);
    if (*str)
        free(*str);
}

static void set_array(char ***res, char **array, char *str)
{
    int index = 0;

    if (array) {
        while (array[index]) {
            (*res)[index] = my_strdup(array[index]);
            index += 1;
        }
    }
    (*res)[index] = my_strdup(str);
}

char **my_append_to_array(char **array, char *str, const int freer)
{
    char **res = NULL;
    int size = my_arrlen(array);

    if (!str)
        return (my_arrdup((char const * const *)array));
    res = malloc(sizeof(char *) * (size + 2));
    if (!res)
        return (NULL);
    res[size + 1] = NULL;
    set_array(&res, array, str);
    if (freer)
        free_assets(array, &str);
    return (res);
}