/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** similar to the stdio function
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

static void init_structures(arr_ptr_t *array_ptr)
{
    array_ptr->list_flag = NULL;
    array_ptr->list_mod = NULL;
}

static void free_lists(path_taker **list_flag, mod_checker **list_mod)
{
    if (!(*list_flag))
        free(*list_flag);
    if (!(*list_mod))
        free(*list_mod);
}

static void browse_through_input(const char *input, va_list ap)
{
    arr_ptr_t redir;
    int idx = 0;

    init_structures(&redir);
    while (input[idx]) {
        if (input[idx] == '%') {
            get_flag(ap, &redir, &input[idx], &idx);
            idx += 2;
        } else
            my_putchar(input[idx]);
        idx += 1;
    }
    free_lists(&redir.list_flag, &redir.list_mod);
}

int my_printf(const char *input, ...)
{
    va_list ap;

    va_start(ap, input);
    browse_through_input(input, ap);
    va_end(ap);
    return (0);
}