/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** redirects towards the my_put_nbr functions
*/

#include "my.h"
#include "my_printf.h"

void flag_d(va_list ap)
{
    my_put_nbr(va_arg(ap, int), "0123456789");
}

void flag_i(va_list ap)
{
    my_put_nbr(va_arg(ap, int), "0123456789");
}

void flag_u(va_list ap)
{
    my_put_nbr_u(va_arg(ap, unsigned int), "0123456789");
}

void flag_b(va_list ap)
{
    my_put_nbr(va_arg(ap, int), "01");
}

void flag_o(va_list ap)
{
    my_put_nbr(va_arg(ap, int), "01234567");
}