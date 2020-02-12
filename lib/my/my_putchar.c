/*
** EPITECH PROJECT, 2019
** library
** File description:
** puts a character onto the stdout
*/

#include <unistd.h>

int my_putchar(const char c)
{
    if (write(1, &c, 1) != 1)
        return (84);
    return (0);
}