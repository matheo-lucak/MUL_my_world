/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_game_structures.c
*/

#include "my_world.h"

sfBool init_game_structures(win_settings_t *win_settings,
                            map_formatter_t *terraformer)
{
    if (!init_win_settings(win_settings))
        return (sfFalse);
    if (!init_terraformer(terraformer, 2000))
        return (sfFalse);
    return (sfTrue);
}