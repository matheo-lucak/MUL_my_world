/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_win_settings.c
*/

#include "my_world.h"

sfBool init_win_settings(win_settings_t *win_settings)
{
    sfFloatRect rect = (sfFloatRect){0, 0, 1920, 1080};

    win_settings->video_mode = (sfVideoMode){1920, 1080, 32};
    win_settings->window = sfRenderWindow_create(win_settings->video_mode,
                        "My_world by Matheo Lucak & Guillaume Bogard-Coquard",
                        sfClose | sfDefaultStyle, NULL);
    if (!win_settings->window)
        return (sfFalse);
    sfRenderWindow_setFramerateLimit(win_settings->window, 60);
    sfRenderWindow_setMouseCursorVisible(win_settings->window, sfTrue);
    win_settings->view = sfView_createFromRect(rect);
    if (!win_settings->view) {
        free_win_settings(win_settings);
        return (sfFalse);
    }
    sfView_setCenter(win_settings->view, vec2f(0, 0));
    win_settings->mode.view_mode = VIEW_ALL;
    return (sfTrue);
}