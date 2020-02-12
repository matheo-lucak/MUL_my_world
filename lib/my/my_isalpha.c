/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** checks if a char is alpha
*/

int my_isalpha(const char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}