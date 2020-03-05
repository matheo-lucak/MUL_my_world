/*
** EPITECH PROJECT, 2020
** mylib
** File description:
** my_memset
*/

void my_memset(char *str, const char c, const int len)
{
    int i = 0;

    while (i < len) {
        str[i] = c;
        i++;
    }
}