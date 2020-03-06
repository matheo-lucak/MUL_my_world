/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Main instance of the game.
*/

#include <stdlib.h>
#include "my.h"
#include "my_world.h"
#include "vector_engine.h"

sfBool my_world(win_settings_t *sets)
{
    map_formatter_t ter;
    fps_assets_t fps_assets;
    sfBool goback_menu = sfFalse;

    if (!init_game_structures(&ter, &fps_assets))
        return (sfFalse);
    sfMusic_setVolume(sets->main_track, 45);
    sfView_setCenter(sets->view, vec2f(0, 0));
    while (game_state_checker(sets->window, &sets->event, &goback_menu)) {
        sfRenderWindow_clear(sets->window, sfBlack);
        game_view_update(sets, &ter, &fps_assets);
        draw_fps(*sets, &fps_assets);
        sfRenderWindow_display(sets->window);
    }
    free_game_structures(&ter, &fps_assets);
    return (goback_menu);
}