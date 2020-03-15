/*
** EPITECH PROJECT, 2019
** my_int_to_str
** File description:
** displays the number given as parameter
*/

#include <stdlib.h>
#include "my.h"

char *my_int_to_str(int nb)
{
    int i = my_int_size(nb);
    char *str = NULL;
    int neg = 0;

    if (nb < 0) {
        neg = 1;
        i += 1;
        nb *= -1;
    }
    str = malloc(sizeof(char) * (i + 1));
    if (!str)
        return (NULL);
    if (neg)
        str[0] = '-';
    str[i] = '\0';
    while (i-- > neg) {
        str[i] = nb % 10 + 48;
        nb /= 10;
    }
    return (str);
}