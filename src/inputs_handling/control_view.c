/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** controls the camera view onto the 3D scene.
*/

#include "my_world.h"
#include "vector_engine.h"

static sfVector2f compute_translation(const sfVector2i mv_speed,
                                    const sfVector2f coeff,
                                    const size_t index)
{
    static sfVector2f (*transl[])(sfVector2i, sfVector2f) = {transl_up,
                                                    transl_down, transl_left,
                                                    transl_right};

    if (index > 3)
        return (vec2f(0, 0));
    return (transl[index](mv_speed, coeff));
}

static void control_camera_translate(win_settings_t sets,
                                    presets_t map_settings,
                                    sfBool *changed)
{
    register size_t index = 0;
    sfVector2i mv_speed = map_settings.movement_speed;
    sfVector2f coeff = sfView_getSize(sets.view);
    int translate_inputs[] = {sfKeyUp, sfKeyDown, sfKeyLeft, sfKeyRight};

    coeff.x /= 2000;
    coeff.y /= 2000;
    while (index < 4) {
        if (sfKeyboard_isKeyPressed(translate_inputs[index])) {
            sfView_move(sets.view, compute_translation(mv_speed, coeff, index));
            *changed = sfTrue;
        }
        index += 1;
    }
}

static void control_camera_rescale(win_settings_t sets,
                                    sfBool *changed)
{
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        if (sfKeyboard_isKeyPressed(sfKeyA))
            return;
        sfView_zoom(sets.view, 1.02);
        *changed = sfTrue;
    }
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        if (sfKeyboard_isKeyPressed(sfKeyE))
            return;
        sfView_zoom(sets.view, 0.98);
        *changed = sfTrue;
    }
}

sfBool control_camera_view(win_settings_t sets, presets_t map_settings)
{
    sfBool changed = sfFalse;

    control_camera_translate(sets, map_settings, &changed);
    control_camera_rescale(sets, &changed);
    sfRenderWindow_setView(sets.window, sets.view);
    return (changed);
}

sfBool control_angle_view(presets_t *map_settings)
{
    register size_t index = 0;
    sfBool changed = sfFalse;
    int rotate_inputs[] = {sfKeyZ, sfKeyS, sfKeyQ, sfKeyD};
    static void (*rotation[])(presets_t *, sfBool *) = {rotate_up, rotate_down,
                                                    rotate_left, rotate_right};

    while (index < 4) {
        if (sfKeyboard_isKeyPressed(rotate_inputs[index]))
            rotation[index](map_settings, &changed);
        index += 1;
    }
    if (map_settings->angles.x < 0)
        map_settings->angles.x += 360;
    else
        map_settings->angles.x %= -360;
    return (changed);
}