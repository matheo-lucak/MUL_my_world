/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Frees win_settings_t structure.
*/

#include <stdlib.h>
#include "my_world.h"

void free_win_settings(win_settings_t sets)
{
    if (sets.view)
        sfView_destroy(sets.view);
    if (sets.window) {
        if (sfRenderWindow_isOpen(sets.window))
            sfRenderWindow_close(sets.window);
        sfRenderWindow_destroy(sets.window);
    }
    if (sets.main_track)
        sfMusic_destroy(sets.main_track);
}