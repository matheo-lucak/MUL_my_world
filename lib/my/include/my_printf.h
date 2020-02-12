/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** header to link files from my_printf program
*/

#ifndef MY_PRINTF_H_

#define MY_PRINTF_H_

#include <stdarg.h>

typedef struct redirect_array {
    void (*flag_list)(va_list ap);
} path_taker;

typedef struct mod_redirect {
    void (*mod_list)(va_list ap, const char *shifted_input, int *idx);
} mod_checker;

typedef struct arr_ptr_s {
    path_taker *list_flag;
    mod_checker *list_mod;
} arr_ptr_t;

int my_printf(const char *input, ...);

int get_flag(va_list ap, arr_ptr_t *redir,
            const char *shifted_input, int *idx);

int check_for_flag(const char c);
int check_for_mod(const char c);
int check_for_base(const char c);

void initialize_path_taker(arr_ptr_t *redir);
void initialize_modifiers(arr_ptr_t *redir);

int my_flag_cmp(const char *to_find, const char *template);

void flag_c(va_list ap);
void flag_d(va_list ap);
void flag_i(va_list ap);
void flag_u(va_list ap);
void flag_b(va_list ap);
void flag_o(va_list ap);
void flag_lower_x(va_list ap);
void flag_upper_x(va_list ap);
void flag_lower_s(va_list ap);
void flag_upper_s(va_list ap);
void flag_p(va_list ap);

void flag_percent(const char *shifted_input, int *idx);

void mod_hashtag(va_list ap, const char *shifted_input, int *idx);
void mod_short(va_list ap, const char *shifted_input, int *idx);
void mod_long(va_list ap, const char *shifted_input, int *idx);

#endif /* MY_PRINTF_H_ */