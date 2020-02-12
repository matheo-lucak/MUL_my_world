/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** frees an array
*/

#include <stdlib.h>

void my_free_arr(char **array)
{
    int i = 0;

    if (!array)
        return;
    while (array[i]) {
        free(array[i]);
        i += 1;
    }
}