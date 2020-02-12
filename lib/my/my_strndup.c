/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** duplicates a string upto a n number of itterations
*/

#include <stdlib.h>
#include "my.h"

char *my_strndup(const char *template, int n)
{
    char *result = NULL;
    int size = my_strnlen(template, n);
    int index = 0;

    if (!template)
        return (NULL);
    result = malloc(sizeof(char) * (size + 1));
    if (!result)
        return (NULL);
    result[size] = '\0';
    while (template[index] && index < n) {
        result[index] = template[index];
        index += 1;
    }
    return (result);
}