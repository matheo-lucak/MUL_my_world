/*
** EPITECH PROJECT, 2019
** PSU_minishell_2019
** File description:
** gets a string len with a n factor
*/

int my_strnlen(const char *str, const int n)
{
    int i = -1;

    if (str)
        while (str[++i] && i < n);
    return (i);
}