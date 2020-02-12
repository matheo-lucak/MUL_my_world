/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** redirects towards the function used for the p flag
*/

#include "my.h"
#include "my_printf.h"

void flag_p(va_list ap)
{
    my_putstr("0x");
    my_put_nbr_lu((unsigned long int)va_arg(ap, void *), "0123456789abcdef");
}