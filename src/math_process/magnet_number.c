/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** magnet_point
*/

#include "my_world.h"

void magnet_number(float *nb, const float offset,
                    const int acc, const float magnet)
{
    int modulo = (int)(acc * magnet);
    int sized_nb;

    if (!nb)
        return;
    sized_nb = (int)(*nb * acc);
    if (*nb >= 0) {
        if (sized_nb % modulo >= (int)(acc * (magnet - offset)))
            *nb += (float)((acc * magnet) - sized_nb % modulo) / acc;
        else if (sized_nb % modulo <= (int)(offset * acc))
            *nb -= (float)(sized_nb % modulo) / acc;
    }
    if (*nb < 0) {
        if ((-sized_nb % modulo) >= (int)(acc * (magnet - offset)))
            *nb -= (float)((acc * magnet) + sized_nb % modulo) / acc;
        else if ((-sized_nb % modulo) <= (int)(offset * acc))
            *nb += (float)(-sized_nb % modulo) / acc;
    }
}