/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** redirects lower and upper streams
*/

#include "my.h"
#include "my_printf.h"

static void print_zeros(int nb)
{
    int count = 100;

    while (nb < count) {
        my_putchar('0');
        count /= 10;
    }
}

void flag_lower_x(va_list ap)
{
    my_put_nbr(va_arg(ap, int), "0123456789abcdef");
}

void flag_upper_x(va_list ap)
{
    my_put_nbr(va_arg(ap, int), "0123456789ABCDEF");
}

void flag_lower_s(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}

void flag_upper_s(va_list ap)
{
    const char *arg = va_arg(ap, const char *);
    int index = 0;

    while (arg[index]) {
        if (arg[index] >= 32 && arg[index] <= 126)
            my_putchar(arg[index]);
        else {
            my_putchar('\\');
            print_zeros((int)arg[index]);
            my_put_nbr((int)arg[index], "01234567");
        }
        index += 1;
    }
}