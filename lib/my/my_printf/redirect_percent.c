/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** computes when a %% or % is used
*/

#include "my_printf.h"
#include "my.h"

static int check_for_double_percents(int *count_percent, const char c)
{
    if (c == '%') {
        *count_percent += 1;
        if ((*count_percent) == 2)
            return (1);
    }
    return (0);
}

void flag_percent(const char *shifted_input, int *idx)
{
    int count_percent = 0;
    int count = 1;

    while (shifted_input[count]) {
        if (check_for_double_percents(&count_percent, shifted_input[count]))
            break;
        my_putchar(shifted_input[count]);
        (*idx) += 1;
        count += 1;
    }
    (*idx) -= 2;
}