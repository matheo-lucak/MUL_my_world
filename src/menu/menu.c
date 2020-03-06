/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** menu.c
*/

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

static sfBool run_menu(win_settings_t sets, menu_assets_t menu_assets)
{
    sfMusic_setVolume(sets.main_track, 75);
    sfView_setSize(sets.view, sets.size);
    sfView_setCenter(sets.view, vec_mult(sets.size, 0.5));
    sfRenderWindow_setView(sets.window, sets.view);
    set_pos(menu_assets.earth, (1920 / 2) - (480 / 2), (1080 / 2) - (400 / 2));
    while (sfKeyboard_isKeyPressed(sfKeyEnter));
    while (!sfKeyboard_isKeyPressed(sfKeyEnter)) {
        if (should_close_window(sets))
            return (sfFalse);
        sfRenderWindow_clear(sets.window, sfBlack);
        udpate_window_settings(&sets);
        update_pixellist(sets, &(menu_assets.pixels), menu_assets.pixel_drawer);
        anime_game_object(menu_assets.earth, 125);
        draw_game_object(sets, menu_assets.earth);
        sfRenderWindow_display(sets.window);
    }
    return (sfTrue);
}

void menu(void)
{
    win_settings_t sets;
    menu_assets_t menu_assets;

    if (!init_win_settings(&sets) || !init_menu_assets(sets, &menu_assets))
        return;
    do {
        udpate_window_settings(&sets);
        if (!run_menu(sets, menu_assets))
            break;
        free_pixels(&(menu_assets.pixels));
    } while (my_world(&sets));
    free_win_settings(sets);
}