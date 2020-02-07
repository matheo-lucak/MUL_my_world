/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** initializes the window
*/

#include "my_world.h"

win_settings_t init_window(void)
{
    win_settings_t win_sets;

    win_sets.video_mode.width = 1920;
    win_sets.video_mode.height = 1080;
    win_sets.video_mode.bitsPerPixel = 32;
    win_sets.window = sfRenderWindow_create(win_sets.video_mode,
                        "My_world by Matheo Lucak & Guillaume Bogard-Coquard",
                        sfClose | sfDefaultStyle, NULL);
    if (!win_sets.window)
        return (win_sets);
    sfRenderWindow_setFramerateLimit(win_sets.window, 60);
    sfRenderWindow_setMouseCursorVisible(win_sets.window, sfTrue);
    win_sets.view = sfView_create();
    if (!win_sets.view)
        return (win_sets);
    sfView_setSize(win_sets.view, (sfVector2f){1920, 1080});
    return (win_sets);
}