/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_hay_needle
*/

int my_strlen(char const *str);

int my_strncmp(const char *first, const char *second, const unsigned int n);

int my_hay_needle(const char *str, const char *to_find)
{
    int i = 0;

    if (!str || !to_find)
        return (-1);
    while (str[i]) {
        if (!my_strncmp(str + i, to_find, my_strlen(to_find)))
            return (i);
        i += 1;
    }
    return (-1);
}