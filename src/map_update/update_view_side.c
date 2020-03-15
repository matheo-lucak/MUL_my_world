/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** update_view_side.c
*/

#include "my_world.h"

void update_view_side(map_formatter_t *ter)
{
    if (ter->map_settings.angles.x > 0 && ter->map_settings.angles.x < 45)
        ter->view_side = BOTTOM;
    if (ter->map_settings.angles.x > 45 && ter->map_settings.angles.x < 90)
        ter->view_side = RIGHT;
    if (ter->map_settings.angles.x > 90 && ter->map_settings.angles.x < 180)
        ter->view_side = TOP;
    if (ter->map_settings.angles.x > 180 && ter->map_settings.angles.x < 360)
        ter->view_side = LEFT;
}