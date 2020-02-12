/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Main instance of the game.
*/

#include "my_world.h"
#include "input_handling.h"

void my_world(void)
{
    map_linked_list_t *my_map = NULL;
    map_formatter_t terraformer;
    win_settings_t win_settings;

    if (!init_game_structures(&win_settings, &terraformer, &my_map))
        return;
    while (should_stay_opened(win_settings.window)) {
        sfRenderWindow_clear(win_settings.window, sfBlack);
        control_camera_view(terraformer.map_settings, win_settings);
        control_angle_view(&(terraformer.map_settings));
        sfRenderWindow_display(win_settings.window);
        break;
    }
    free_game_structures(&win_settings, &terraformer, &my_map);
}