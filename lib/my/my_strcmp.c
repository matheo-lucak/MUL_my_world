/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** returns negative nb if first < second
*/

#include "my.h"

int my_strcmp(const char *first, const char *second, const int splitter)
{
    int len_first = my_strlen(first);
    int len_second = my_strlen(second);
    int index_first = 0;
    int index_second = 0;

    if (len_first == -1 || len_second == -1)
        return (len_first - len_second);
    while (first[index_first] && second[index_second]) {
        if (first[index_first] != second[index_second])
            break;
        index_first += 1;
        index_second += 1;
        while (first[index_first] && first[index_first] == splitter)
            index_first += 1;
        while (second[index_second] && second[index_second] == splitter)
            index_second += 1;
    }
    return (first[index_first] - second[index_second]);
}
