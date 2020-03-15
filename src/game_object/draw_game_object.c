/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Draws a game_obj.
*/

#include "my_world.h"
#include "game_object.h"

void anime_game_object(game_obj_t *obj, const int lapse)
{
    sfClock *clock = obj->comp[find_comp(obj, CLOCK)]->clock;
    sfUint32 msecond = sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
    int frame = 0;

    if (!(obj->view_box.width))
        return ;
    frame = obj->view_box.left / obj->view_box.width;
    if (lapse * (frame + 1) < (int)msecond &&
        lapse * (frame + 2) > (int)msecond &&
        obj->view_box.left == frame * obj->view_box.width)
        obj->view_box.left += obj->view_box.width;
    if (lapse * (int)obj->frame_nb < (int)msecond) {
        sfClock_restart(clock);
        obj->view_box.left = 0;
    }
}

void set_game_object_frame(game_obj_t *obj, unsigned int frame)
{
    if (!obj || obj->frame_nb < frame)
        return ;
    obj->view_box.left = frame * obj->view_box.width;
}

void draw_game_object(win_settings_t sets, game_obj_t *obj)
{
    set_hitbox(obj);
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setTextureRect(obj->sprite, obj->view_box);
    obj->hitbox = sfSprite_getGlobalBounds(obj->sprite);
    sfRenderWindow_drawSprite(sets.window, obj->sprite, NULL);
}