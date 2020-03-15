/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Main instance of the game.
*/

#include <stdlib.h>
#include "my.h"
#include "my_world.h"
#include "game_object.h"
#include "vector_engine.h"

static void start_my_world_resets(win_settings_t *sets)
{
    sfMusic_setVolume(sets->main_track, 1);
    sfView_setCenter(sets->view, vec2f(0, 0));
    sets->paused = sfFalse;
}

static void check_for_pause(sfBool *paused)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        *paused = *paused ? sfFalse : sfTrue;
        while (sfKeyboard_isKeyPressed(sfKeyEscape));
    }
}

sfBool my_world(win_settings_t *sets)
{
    sfBool goback_menu = sfFalse;
    map_formatter_t ter;
    hud_t hud;

    if (!init_game_structures(&ter, &hud))
        return (sfFalse);
    start_my_world_resets(sets);
    while (game_state_checker(sets->window, &sets->event, &goback_menu)) {
        check_for_pause(&sets->paused);
        sfRenderWindow_clear(sets->window, sfBlack);
        game_view_update(sets, &ter, &hud);
        sfRenderWindow_display(sets->window);
    }
    free_game_structures(&ter, &hud);
    florian_the_toucan_wants_to_speak(NULL, NULL, 1);
    return (goback_menu);
}