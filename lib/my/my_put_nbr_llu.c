/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** puts a nb on stdout considering its base
*/

#include "my.h"

void my_put_nbr_llu(unsigned long long int nb, const char *base)
{
    static int len_base = -2;

    if (len_base == -2) {
        len_base = my_strlen(base);
        if (len_base < 1)
            return;
    }
    if (nb >= (unsigned long long int)len_base) {
        my_put_nbr_llu(nb / len_base, base);
        my_put_nbr_llu(nb % len_base, base);
    } else
        my_putchar(base[nb]);
}
