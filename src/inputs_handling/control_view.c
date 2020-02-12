/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** controls the camera view onto the 3D scene.
*/

#include "my_world.h"

static void control_camera_translate(win_settings_t win_settings,
                                    presets_t map_settings, sfBool *changed)
{
    sfVector2i mv_speed = map_settings.movement_speed;

    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        sfView_move(win_settings.view, (sfVector2f){mv_speed.x, 0});
        *changed = sfTrue;
    } else if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        sfView_move(win_settings.view, (sfVector2f){mv_speed.x * -1, 0});
        *changed = sfTrue;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        sfView_move(win_settings.view, (sfVector2f){0, mv_speed.y * -1});
        *changed = sfTrue;
    } else if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        sfView_move(win_settings.view, (sfVector2f){0, mv_speed.y});
        *changed = sfTrue;
    }
}

static void control_camera_rescale(win_settings_t win_settings,
                                    sfBool *changed)
{
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        sfView_zoom(win_settings.view, 1.02);
        *changed = sfTrue;
    }
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        sfView_zoom(win_settings.view, 0.98);
        *changed = sfTrue;
    }
}

sfBool control_camera_view(presets_t map_settings,
                             win_settings_t win_settings)
{
    sfBool changed = sfFalse;

    control_camera_translate(win_settings, map_settings, &changed);
    control_camera_rescale(win_settings, &changed);
    sfRenderWindow_setView(win_settings.window, win_settings.view);
    return (changed);
}

sfBool control_angle_view(presets_t *map_settings)
{
    sfBool changed = sfFalse;

    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        map_settings->angle_y -= map_settings->rotation_speed.y;
        changed = sfTrue;
    } else if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        map_settings->angle_y += map_settings->rotation_speed.y;
        changed = sfTrue;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        map_settings->angle_x -= map_settings->rotation_speed.x;
        changed = sfTrue;
    } else if (sfKeyboard_isKeyPressed(sfKeyD)) {
        map_settings->angle_x += map_settings->rotation_speed.x;
        changed = sfTrue;
    }
    return (changed);
}