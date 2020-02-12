/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** free_map.c
*/

#include <stdlib.h>

void free_array(void **array, const unsigned int size)
{
    int index = 0;

    if (!array)
        return;
    while (index < size) {
        if (array[index])
            free(array[index]);
        index += 1;
    }
    if (array)
        free(array);
}