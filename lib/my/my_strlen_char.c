/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** gets a string len until meeting a certain char
*/

int my_strlen_char(const char *str, const char c)
{
    int i = -1;

    if (str)
        while (str[++i] && str[i] != c);
    return (i);
}