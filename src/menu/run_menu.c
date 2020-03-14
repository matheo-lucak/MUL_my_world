/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** run_menu.c
*/

#include <math.h>
#include "my.h"
#include "my_world.h"
#include "game_menu.h"
#include "game_object.h"
#include "vector_engine.h"
#include "input_handling.h"
#include "pixel.h"

static sfBool should_close_window(win_settings_t sets)
{
    if (!sfRenderWindow_isOpen(sets.window))
        return (sfTrue);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        return (sfTrue);
    if (sfRenderWindow_pollEvent(sets.window, &sets.event)
        && sets.event.type == sfEvtClosed)
        return (sfTrue);
    return (sfFalse);
}

static void reset_settings_for_menu(win_settings_t sets,
                                    menu_assets_t menu_assets)
{
    sfMusic_setVolume(sets.main_track, 1);
    sfView_setSize(sets.view, sets.size);
    sfView_setCenter(sets.view, vec_mult(sets.size, 0.5));
    sfRenderWindow_setView(sets.window, sets.view);
    set_pos(menu_assets.earth,
            sets.video_mode.width / 2,
            sets.video_mode.height / 2);
}

sfBool run_menu(win_settings_t sets, menu_assets_t menu_assets)
{
    sfBool close_window = sfFalse;

    reset_settings_for_menu(sets, menu_assets);
    while (sfKeyboard_isKeyPressed(sfKeyEnter));
    while (!sfKeyboard_isKeyPressed(sfKeyEnter) && !close_window) {
        sfRenderWindow_clear(sets.window, sfBlack);
        udpate_window_settings(&sets);
        update_pixellist(sets, &(menu_assets.pixels), menu_assets.pixel_drawer);
        anime_game_object(menu_assets.earth, 125);
        draw_game_object(sets, menu_assets.earth);
        sfRenderWindow_display(sets.window);
        close_window = should_close_window(sets);
    }
    return (close_window);
}