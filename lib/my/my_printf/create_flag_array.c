/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** allocates and creates the arrays of function pointers
*/

#include <stdlib.h>
#include "my_printf.h"

void initialize_modifiers(arr_ptr_t *redir)
{
    redir->list_mod = malloc(sizeof(mod_checker) * 4);
    if (!(redir->list_mod))
        return;
    redir->list_mod[0].mod_list = &mod_hashtag;
    redir->list_mod[1].mod_list = &mod_short;
    redir->list_mod[2].mod_list = &mod_long;
    redir->list_mod[3].mod_list = &mod_long;
}

void initialize_path_taker(arr_ptr_t *redir)
{
    redir->list_flag = malloc(sizeof(path_taker) * 11);
    if (!(redir->list_flag))
        return;
    redir->list_flag[0].flag_list = &flag_c;
    redir->list_flag[1].flag_list = &flag_d;
    redir->list_flag[2].flag_list = &flag_i;
    redir->list_flag[3].flag_list = &flag_u;
    redir->list_flag[4].flag_list = &flag_b;
    redir->list_flag[5].flag_list = &flag_o;
    redir->list_flag[6].flag_list = &flag_lower_x;
    redir->list_flag[7].flag_list = &flag_upper_x;
    redir->list_flag[8].flag_list = &flag_lower_s;
    redir->list_flag[9].flag_list = &flag_upper_s;
    redir->list_flag[10].flag_list = &flag_p;
}