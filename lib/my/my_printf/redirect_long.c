/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** redirects towards the called function with long flag
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

static void ll_arg(const int count, int *idx)
{
    if (count == 2 || count == 3 || count == 7)
        (*idx) += 1;
}

static void long_redir(va_list ap, const int count, int *idx)
{
    if (count == 0 || count == 1) {
        my_put_nbr_l(va_arg(ap, long int), "0123456789");
        (*idx) += 1;
    }
    if (count >= 2 && count <= 5) {
        my_put_nbr_ll(va_arg(ap, long long int), "0123456789");
        ll_arg(count, idx);
        (*idx) += 1;
    }
    if (count == 6) {
        my_put_nbr_lu(va_arg(ap, unsigned long int), "0123456789");
        (*idx) += 1;
    }
    if (count == 7 || count == 8) {
        my_put_nbr_llu(va_arg(ap, unsigned long long int), "0123456789");
        ll_arg(count, idx);
        (*idx) += 1;
    }
}

void mod_long(va_list ap, const char *shifted_input, int *idx)
{
    static const char * const cmp[] = {"ld", "li", "lld", "lli",
                                    "qd", "qi", "lu", "llu", "qu"};
    int count = 0;

    while (cmp[count]) {
        if (!my_flag_cmp(&shifted_input[1], cmp[count]))
            break;
        count += 1;
    }
    long_redir(ap, count, idx);
}