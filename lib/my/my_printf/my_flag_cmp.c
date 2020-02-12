/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** checks if a used flag is matching to a real flag
*/

#include "my.h"

int my_flag_cmp(const char *to_find, const char *template)
{
    int i = 0;
    int n = my_strlen(template);
    int match = 0;

    while ((to_find[i] && template[i]) || i < n) {
        if (to_find[i] != template[i])
            return (1);
        if (to_find[i] == template[i])
            match += 1;
        i += 1;
    }
    if (match == n)
        return (0);
    return (1);
}