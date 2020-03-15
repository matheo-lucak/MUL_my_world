/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Running interractions between the menu and the my_world.
*/

#include "game_menu.h"
#include "my_world.h"

void window_actions(void)
{
    win_settings_t sets;
    menu_assets_t menu_assets;

    if (!init_win_settings(&sets) || !init_menu_assets(sets, &menu_assets))
        return;
    do {
        update_window_settings(&sets);
        if (run_menu(sets, menu_assets))
            break;
        free_pixels(&(menu_assets.pixels));
    } while (my_world(&sets));
    free_win_settings(sets);
}