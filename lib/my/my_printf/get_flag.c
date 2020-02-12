/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** gets the called flag and redirects towards the matching function
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

static void free_arrays(arr_ptr_t *redir)
{
    if (redir->list_flag) {
        free(redir->list_flag);
        redir->list_flag = NULL;
    } if (redir->list_mod) {
        free(redir->list_mod);
        redir->list_mod = NULL;
    }
}

static int initialize_arrays(arr_ptr_t *redir)
{
    if (!(redir->list_flag)) {
        initialize_path_taker(redir);
        if (!(redir->list_flag))
            return (0);
    }
    if (!(redir->list_mod)) {
        initialize_modifiers(redir);
        if (!(redir->list_mod)) {
            free_arrays(redir);
            return (0);
        }
    }
    return (1);
}

static int check_behind(va_list ap, arr_ptr_t *redir,
                        const char *shifted_input, int *idx)
{
    int call_redir = 0;

    call_redir = check_for_flag(shifted_input[1]);
    if (call_redir > -1) {
        redir->list_flag[call_redir].flag_list(ap);
        return (0);
    }
    call_redir = check_for_mod(shifted_input[1]);
    if (call_redir > -1) {
        redir->list_mod[call_redir].mod_list(ap, shifted_input, idx);
        return (0);
    }
    return (1);
}

static int few_cases(const char *shifted_input, int *idx,
                        const int call_redir)
{
    if (shifted_input[1] && call_redir == 1) {
        my_putchar('%');
        my_putchar(shifted_input[1]);
        return (0);
    }
    if (shifted_input[1]) {
        (*idx) -= 1;
        return (0);
    }
    return (1);
}

int get_flag(va_list ap, arr_ptr_t *redir, const char *shifted_input, int *idx)
{
    int call_redir = 0;

    if (!initialize_arrays(redir))
        return (84);
    call_redir = check_behind(ap, redir, shifted_input, idx);
    if (shifted_input[1] == '%') {
        flag_percent(shifted_input, idx);
        (*idx) += 1;
        free_arrays(redir);
        return (0);
    }
    if (!(few_cases(shifted_input, idx, call_redir))) {
        free_arrays(redir);
        return (0);
    }
    free_arrays(redir);
    return (-1);
}