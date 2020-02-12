/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** redirects towards the correct function when a hashtag flag is detected
*/

#include "my.h"
#include "my_printf.h"

static void normal_print(va_list ap, const int base)
{
    if (base == 0 || base == 1)
        flag_d(ap);
    else if (base == 2)
        flag_u(ap);
    else
        flag_b(ap);
}

static void modified(va_list ap, const int base)
{
    int octal_save = 0;

    if (base == 4) {
        octal_save = va_arg(ap, int);
        if (octal_save > 0)
            my_putchar('0');
        my_put_nbr(octal_save, "01234567");
    } else if (base == 5)
        my_printf("0x%x", va_arg(ap, int));
    else
        my_printf("0x%X", va_arg(ap, int));
}

void mod_hashtag(va_list ap, const char *shifted_input, int *idx)
{
    int base = 0;

    base = check_for_base(shifted_input[2]);
    if (base == -1)
        return;
    if (base < 4)
        normal_print(ap, base);
    else
        modified(ap, base);
    (*idx) += 1;
}