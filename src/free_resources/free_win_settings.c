/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** free_win_settings.c
*/

#include <stdlib.h>
#include "my_world.h"

void free_win_settings(win_settings_t win_settings)
{
    if (win_settings.view)
        sfView_destroy(win_settings.view);
    if (win_settings.window) {
        if (sfRenderWindow_isOpen(win_settings.window))
            sfRenderWindow_close(win_settings.window);
        sfRenderWindow_destroy(win_settings.window);
    }
    if (win_settings.main_track)
        sfMusic_destroy(win_settings.main_track);
}