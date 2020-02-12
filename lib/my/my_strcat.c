/*
** EPITECH PROJECT, 2019
** library
** File description:
** concats two strings
*/

#include <stdlib.h>
#include "my.h"

static char *compute_concat(const char *core,
                            const char *to_append,
                            const int len_str,
                            const int len_append)
{
    char *result = NULL;
    int count_templates = 0;
    int count_res = 0;

    result = malloc(sizeof(char) * (len_str + len_append + 1));
    if (!result)
        return (NULL);
    while (core[count_templates]) {
        result[count_res] = core[count_templates];
        count_templates += 1;
        count_res += 1;
    }
    count_templates = 0;
    while (to_append[count_templates]) {
        result[count_res] = to_append[count_templates];
        count_templates += 1;
        count_res += 1;
    }
    result[count_res] = '\0';
    return (result);
}

char *my_strcat(const char *core, const char *to_append)
{
    int len_str = my_strlen(core);
    int len_append = my_strlen(to_append);

    if (len_str <= 0 || len_append <= 0)
        return (len_str <= 0) ? my_strdup(to_append) : my_strdup(core);
    return (compute_concat(core, to_append, len_str, len_append));
}