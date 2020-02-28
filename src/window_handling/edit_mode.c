/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** edit_mode
*/

#include "my_world.h"

void change_edit_mode(game_mode_t *mode, edit_mode_flag_t flag)
{
    if (!mode)
        return ;
    mode->edit_mode = 0;
    mode->edit_mode |= flag;
}

void set_view_mode(game_mode_t *mode, view_mode_t flag)
{
    if (!mode)
        return ;
    mode->view_mode |= flag;
}

void unset_view_mode(game_mode_t *mode, view_mode_t flag)
{
    if (!mode)
        return ;
    mode->view_mode ^= flag;
}

sfBool is_view_mode(game_mode_t mode, view_mode_t flag)
{
    if (mode.view_mode & flag)
        return (sfTrue);
    return (sfFalse);
}