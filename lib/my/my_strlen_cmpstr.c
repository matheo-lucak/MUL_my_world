/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** gets a string len until meeting a certain char
*/

#include "my.h"

int my_strlen_cmpstr(const char *str, const char cmp[])
{
    int i = -1;

    if (str)
        while (str[++i] && !find_char_in_str(cmp, str[i]));
    return (i);
}