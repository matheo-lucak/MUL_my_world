/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** compares two strings for n chars
*/

#include "my.h"

int my_strncmp(const char *first, const char *second, const unsigned int n)
{
    unsigned int index = 0;

    if (!first || !second)
        return (first - second);
    while (first[index] && second[index] && index < n) {
        if (first[index] != second[index])
            return (first[index] - second[index]);
        index += 1;
    }
    return (0);
}
