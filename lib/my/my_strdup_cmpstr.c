/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** duplicates a string upto a certain list of characters
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup_cmpstr(const char *template, const char cmp[])
{
    char *result = NULL;
    int size = my_strlen_cmpstr(template, cmp);
    int count_dup = 0;

    if (!template)
        return (NULL);
    result = malloc(sizeof(char) * (size + 1));
    if (!result)
        return (NULL);
    result[size] = '\0';
    while (count_dup < size) {
        result[count_dup] = template[count_dup];
        count_dup += 1;
    }
    return (result);
}