/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** gets the size of an array
*/

int my_arrlen(char **array)
{
    int i = 0;

    if (array)
        while (array[i])
            i += 1;
    return (i);
}