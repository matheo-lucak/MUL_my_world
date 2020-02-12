/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** redirects to the my_putchar function when a matching flag is found
*/

#include "my.h"
#include "my_printf.h"

void flag_c(va_list ap)
{
    my_putchar(va_arg(ap, int));
}