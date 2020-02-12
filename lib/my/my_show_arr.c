/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_show_arr.c
*/

#include "my.h"

void my_show_arr(char **array)
{
    int index = 0;

    if (!array)
        return;
    while (array[index]) {
        my_printf("%s\n", array[index]);
        index += 1;
    }
}