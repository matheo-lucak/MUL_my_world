/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Pixel gravity physics
*/

#include "vector_engine.h"
#include "pixel.h"
#include "my_world.h"
#include "game_object.h"
#include "my_graphical.h"

static void pixel_bounce_window(win_settings_t sets, pixellist_t *pixel)
{
    if (!pixel)
        return ;
    if ((pixel->pos.x < 0 && pixel->vel.x < 0)
        || (pixel->pos.x > sets.video_mode.width && pixel->vel.x > 0))
        pixel->vel.x *= -1;
    if ((pixel->pos.y < 0 && pixel->vel.y < 0)
        || (pixel->pos.y > sets.video_mode.height && pixel->vel.y > 0)) {
        pixel->vel.y *= -1;
    }
}

static void apply_gravity(pixellist_t *pixel, const sfVector2f gravity_center,
                        const sfVector2f lims, const float power)
{
    float distance = 0;
    float strength = 0;

    pixel->acc = vec_mult(pixel->pos, -1);
    pixel->acc = vec_add(pixel->acc, gravity_center);
    distance = vec_mag(pixel->acc);
    pixel->acc = vec_norm(pixel->acc);
    if (distance > lims.y)
        distance = lims.y;
    else if (distance < lims.x)
        distance = lims.x;
    strength = power / (distance * distance);
    pixel->acc = vec_mult(pixel->acc, strength);
}

void update_pixel_physic(win_settings_t sets, pixellist_t *pixel)
{
    sfVector2f lims = {0, 0};

    if (!pixel)
        return ;
    pixel->acc = (sfVector2f) {0, 0};
    if (sets.mouse_tool.hold) {
        lims = vec2f(50, 1000);
        apply_gravity(pixel, sets.mouse_tool.pos, lims, 5000);
    }
    pixel_bounce_window(sets, pixel);
    pixel->vel = vec_add(pixel->vel, pixel->acc);
    pixel->vel = vec_lim(pixel->vel, vec2f(3, 3), vec2f(-3, -3));
    pixel->pos = vec_add(pixel->pos, pixel->vel);
}