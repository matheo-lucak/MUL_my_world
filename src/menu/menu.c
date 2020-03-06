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

static sfBool should_close_window(win_settings_t win_settings)
{
    if (!sfRenderWindow_isOpen(win_settings.window))
        return (sfTrue);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        return (sfTrue);
    if (sfRenderWindow_pollEvent(win_settings.window, &win_settings.event)
        && win_settings.event.type == sfEvtClosed)
        return (sfTrue);
    return (sfFalse);
}

static sfBool run_menu(win_settings_t win_settings, menu_assets_t menu_assets)
{
    sfMusic_setVolume(win_settings.main_track, 75);
    sfView_setSize(win_settings.view, win_settings.size);
    sfView_setCenter(win_settings.view, vec_mult(win_settings.size, 0.5));
    sfRenderWindow_setView(win_settings.window, win_settings.view);
    while (sfKeyboard_isKeyPressed(sfKeyEnter));
    while (!sfKeyboard_isKeyPressed(sfKeyEnter)) {
        if (should_close_window(win_settings))
            return (sfFalse);
        sfRenderWindow_clear(win_settings.window, sfBlack);
        udpate_window_settings(&win_settings);
        update_pixellist(win_settings, menu_assets.pixels, menu_assets.pixel_drawer);
        anime_game_object(menu_assets.earth, 125);
        sfSprite_setPosition(menu_assets.earth->sprite, menu_assets.earth->pos);
        sfRenderWindow_drawSprite(win_settings.window, menu_assets.earth->sprite, NULL);
        sfRenderWindow_display(win_settings.window);
    }
    return (sfTrue);
}

void menu(void)
{
    win_settings_t win_settings;
    menu_assets_t menu_assets;

    if (!init_win_settings(&win_settings)
        || !init_menu_assets(win_settings, &menu_assets))
        return;
    do {
        udpate_window_settings(&win_settings);
        if (!run_menu(win_settings, menu_assets))
            break;
    } while (my_world(&win_settings));
    free_win_settings(win_settings);
}