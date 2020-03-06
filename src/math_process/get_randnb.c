/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** get_randnb
*/

#include "stdlib.h"

int get_randomnb(int min, int max)
{
    static int i = 0;
    int nb = 0;

    if (!i) {
        srand((size_t)&i);
        i++;
    }
    if (max == min)
        return (rand() % max);
    nb = rand() % (max - min) + min;
    return (nb);
}