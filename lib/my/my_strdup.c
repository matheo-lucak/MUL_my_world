/*
** EPITECH PROJECT, 2019
** library
** File description:
** duplicates a string with allocation
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(const char *template)
{
    char *dup = NULL;
    int len_template = my_strlen(template);
    int count_dup = 0;

    if (len_template == -1)
        return (NULL);
    dup = malloc(sizeof(char) * (len_template + 1));
    if (!dup)
        return (NULL);
    while (template[count_dup]) {
        dup[count_dup] = template[count_dup];
        count_dup += 1;
    }
    dup[count_dup] = '\0';
    return (dup);
}