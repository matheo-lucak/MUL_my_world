/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** puts a nb on stdout considering its base
*/

#include "my.h"

void my_put_nbr_l(long int nb, const char *base)
{
    static int len_base = -2;

    if (len_base == -2) {
        len_base = my_strlen(base);
        if (len_base < 1)
            return;
    }
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr_l(-nb, base);
    }
    if (nb >= (long int)len_base) {
        my_put_nbr_l(nb / len_base, base);
        my_put_nbr_l(nb % len_base, base);
    } else
        my_putchar(base[nb]);
}
