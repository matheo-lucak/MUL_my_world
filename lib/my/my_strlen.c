/*
** EPITECH PROJECT, 2019
** library
** File description:
** gets a string length
*/

int my_strlen(char const *str)
{
    int i = -1;

    if (str)
        while (str[++i]);
    return (i);
}