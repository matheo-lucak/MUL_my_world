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

static void apply_force(pixellist_t *pixel, sfVector2f force)
{
    force = vec_mult(force, 1 / 1);
    pixel->acc = vec_add(force, pixel->acc);
}

static void pixel_bounce_window(win_settings_t sets, pixellist_t *pixel)
{
    sfVector2f pos = pixel->pos;

    pos = sfRenderWindow_mapPixelToCoords(sets.window,
                                        vec2i(pos.x, pos.y),
                                        sets.view);
    if ((pos.x < sets.anchor.topleft.x && pixel->vel.x < 0)
        || (pos.x > sets.anchor.topright.x && pixel->vel.x > 0))
        pixel->vel.x *= -1;
    if ((pos.y < sets.anchor.topleft.y && pixel->vel.y < 0)
        || (pos.y > sets.anchor.bottomleft.y && pixel->vel.y > 0))
        pixel->vel.y *= -1;
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
    sfVector2i mouse_pos_int = {0, 0};
    sfVector2f lims = {0, 0};
    sfVector2f click_coords = {0, 0};

    if (!pixel)
        return ;
    pixel->acc = (sfVector2f) {0, 0};
    if (sets.mouse_tool.hold) {
        mouse_pos_int = conv_vec2f_vec2i(sets.mouse_tool.pos);
        lims = vec2f(50, 1000);
        click_coords = sfRenderWindow_mapPixelToCoords(sets.window,
                                                        mouse_pos_int,
                                                        sets.view);
        apply_gravity(pixel, click_coords, lims, 5000);
    }
    pixel_bounce_window(sets, pixel);
    pixel->vel = vec_add(pixel->vel, pixel->acc);
    pixel->vel = vec_lim(pixel->vel, (sfVector2f){3, 3}, (sfVector2f){-3, -3});
    pixel->pos = vec_add(pixel->pos, pixel->vel);
}