/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_game_object
*/

#include "game_object.h"

void anime_game_object(game_obj_t *obj)
{
    static sfClock *clock = NULL;
    if (!clock)
        clock = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);
    sfUint32 msecond = sfTime_asMilliseconds(time);
    int frame = obj->view_box.left / obj->view_box.width;

    if (300 * (frame + 1) < (int)msecond &&
        300 * (frame + 2) > (int)msecond &&
        obj->view_box.left == frame * obj->view_box.width)
        obj->view_box.left += obj->view_box.width;
    if (300 * 13 < (int)msecond) {
        sfClock_restart(clock);
        obj->view_box.left = 0;
    }
}