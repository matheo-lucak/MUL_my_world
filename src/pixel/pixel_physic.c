/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** simple_physic
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

static void pixel_bounce_window(win_settings_t win_settings, pixellist_t *pixel)
{
    sfVector2f pos = pixel->pos;

    pos = sfRenderWindow_mapPixelToCoords(win_settings.window,
                        vec2i(pos.x, pos.y), win_settings.view);
    if ((pos.x < win_settings.anchor.topleft.x && pixel->vel.x < 0)
        || (pos.x > win_settings.anchor.topright.x
                                                    && pixel->vel.x > 0))
        pixel->vel.x *= -1;
    if ((pos.y < win_settings.anchor.topleft.y && pixel->vel.y < 0)
        || (pos.y > win_settings.anchor.bottomleft.y
                                                    && pixel->vel.y > 0))
        pixel->vel.y *= -1;
}

static void apply_gravity(pixellist_t *pixel, sfVector2f gravity_center,
                            sfVector2f lims, float power)
{
    float distance;
    float strength;

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

void update_pixel_physic(win_settings_t win_settings, pixellist_t *pixel)
{
    if (!pixel)
        return ;
    pixel->acc = (sfVector2f) {0, 0};
    if (win_settings.mouse_tool.hold) {
        apply_gravity(pixel, sfRenderWindow_mapPixelToCoords(win_settings.window,
            conv_vec2f_vec2i(win_settings.mouse_tool.pos), win_settings.view),
                                            vec2f(50, 1000), 5000);
    }
    pixel_bounce_window(win_settings, pixel);
    pixel->vel = vec_add(pixel->vel, pixel->acc);
    pixel->vel = vec_lim(pixel->vel, (sfVector2f){3, 3}, (sfVector2f){-3, -3});
    pixel->pos = vec_add(pixel->pos, pixel->vel);
}