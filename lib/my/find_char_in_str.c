/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** finds a char into a string
*/

int find_char_in_str(const char *str, const char c)
{
    int index = 0;

    if (!str)
        return (0);
    while (str[index]) {
        if (str[index] == c)
            return (1);
        index += 1;
    }
    return (0);
}