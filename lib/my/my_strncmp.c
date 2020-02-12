/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** compares two strings for n chars
*/

#include "my.h"

int my_strncmp(const char *first, const char *second, const unsigned int n)
{
    int index = 0;

    if (!first || !second) {
        if (!first && !second)
            return (0);
        return (1);
    }
    while (index < (int)n) {
        if (first[index] != second[index])
            return (1);
        index += 1;
    }
    return (0);
}
