/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_game_structures.c
*/

#include "my_world.h"

const sfBool init_game_structures(win_settings_t *win_settings,
                                map_formatter_t *terraformer,
                                map_linked_list_t **my_map)
{
    sfVector2i map_limits = (sfVector2i){terraformer->map_settings.map_x,
                                        terraformer->map_settings.map_y};

    if (!init_win_settings(win_settings))
        return (sfFalse);
    if (!init_terraformer(terraformer, 0)) {
        free_game_structures(win_settings, terraformer, my_map);
        return (sfFalse);
    }
    create_map_list(my_map, map_limits, terraformer->textures, terraformer->shaders);
    if (!my_map) {
        free_game_structures(win_settings, terraformer, my_map);
        return (sfFalse);
    }
    return (sfTrue);
}