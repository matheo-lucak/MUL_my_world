/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** returns nb from a str
*/

#include "my.h"

static int get_sign(const char *str, int *index)
{
    int neg = 1;

    while (str[(*index)] && (str[(*index)] == '+' || str[(*index)] == '-')) {
        if (str[(*index)] == '-')
            neg *= -1;
        (*index) += 1;
    }
    return (neg);
}

int my_getnbr(const char *str)
{
    int index = 0;
    int neg = 1;
    int nb = 0;

    if (!str)
        return (0);
    neg = get_sign(str, &index);
    if (my_strcmp(&str[index], "2147483647", 0) > 0)
        return (0);
    while (str[index] && str[index] >= '0' && str[index] <= '9') {
        if (index > 0)
            nb *= 10;
        nb += str[index] - 48;
        index += 1;
    }
    return (nb * neg);
}