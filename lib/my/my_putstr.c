/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** put chars from a string
*/

#include <unistd.h>
#include "my.h"

int my_putstr(const char *str)
{
    int size = my_strlen(str);

    if (size == -1)
        return (84);
    if (write(1, str, size) != size)
        return (84);
    return (0);
}