/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Initializes the game structures.
*/

#include "my_world.h"

sfBool init_game_structures(map_formatter_t *ter,
                            hud_t *hud)
{
    if (!init_terraformer(ter, 1))
        return (sfFalse);
    if (!init_hud(hud))
        return (sfFalse);
    return (sfTrue);
}