/*
** EPITECH PROJECT, 2019
** library
** File description:
** puts a short unsigned nb on stdout considering its base
*/

#include "my.h"

void my_put_nbr_s(short int nb, const char *base)
{
    static int len_base = -2;

    if (len_base == -2) {
        len_base = my_strlen(base);
        if (len_base < 1)
            return;
    }
    if (nb >= (short int)len_base) {
        my_put_nbr_s(nb / len_base, base);
        my_put_nbr_s(nb % len_base, base);
    } else
        my_putchar(base[nb]);
}
