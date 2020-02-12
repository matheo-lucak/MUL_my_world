/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** redirects when a short flag is called
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

static void short_redir(va_list ap, const int count, int *idx)
{
    if (count == 0 || count == 1) {
        my_put_nbr_s(va_arg(ap, int), "0123456789");
        (*idx) += 1;
    }
    if (count == 2) {
        my_put_nbr_su(va_arg(ap, unsigned int), "0123456789");
        (*idx) += 1;
    }
    if (count == 3 || count == 4) {
        my_put_nbr(va_arg(ap, int), "0123456789");
        (*idx) += 2;
    }
    if (count == 5) {
        my_put_nbr(va_arg(ap, int), "0123456789");
        (*idx) += 2;
    }
}

void mod_short(va_list ap, const char *shifted_input, int *idx)
{
    static const char * const cmp[] = {"hd", "hi", "hu", "hhd", "hhi", "hhu"};
    int count = 0;

    while (cmp[count]) {
        if (!my_flag_cmp(&shifted_input[1], cmp[count]))
            break;
        count += 1;
    }
    short_redir(ap, count, idx);
}