/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** checks if a char is numerical
*/

int my_isnum(const char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}