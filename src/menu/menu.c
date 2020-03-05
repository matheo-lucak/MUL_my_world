/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** menu.c
*/

#include "my_world.h"

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

static sfBool run_menu(win_settings_t win_settings)
{
    sfMusic_setVolume(win_settings.main_track, 75);
    sfView_reset(win_settings.view, (sfFloatRect){0, 0, 1920, 1080});
    while (sfKeyboard_isKeyPressed(sfKeyEnter));
    while (!sfKeyboard_isKeyPressed(sfKeyEnter)) {
        if (should_close_window(win_settings))
            return (sfFalse);
        sfRenderWindow_clear(win_settings.window, sfBlack);
        sfRenderWindow_display(win_settings.window);
    }
    return (sfTrue);
}

void menu(void)
{
    win_settings_t win_settings;

    if (!init_win_settings(&win_settings))
        return;
    do {
        if (!run_menu(win_settings))
            break;
    } while (my_world(&win_settings));
    free_win_settings(win_settings);
}