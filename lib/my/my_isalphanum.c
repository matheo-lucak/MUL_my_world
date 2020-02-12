/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** checks if a char is alphanum
*/

#include "my.h"

int my_isalphanum(const char c)
{
    if (my_isalpha(c) | my_isnum(c))
        return (1);
    return (0);
}