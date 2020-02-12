/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** free_win_sets.c
*/

#include "my_world.h"

void free_win_sets(win_settings_t *win_sets)
{
    if (win_sets->view)
        sfView_destroy(win_sets->view);
    if (win_sets->window)
        sfRenderWindow_destroy(win_sets->window);
}