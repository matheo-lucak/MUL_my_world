/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Frees an array up to a size.
*/

#include <stdlib.h>

void free_array(void **array, const int size)
{
    int index = 0;

    if (!array)
        return;
    while (array[index] && index < size) {
        if (array[index])
            free(array[index]);
        index += 1;
    }
    if (array)
        free(array);
}