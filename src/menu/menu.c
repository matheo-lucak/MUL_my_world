/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** menu.c
*/

#include "my_world.h"

static sfBool run_menu(win_settings_t win_settings)
{
    static sfEvent event;

    sfMusic_setVolume(win_settings.main_track, 75);
    sfView_reset(win_settings.view, (sfFloatRect){0, 0, 1920, 1080});
    while (sfKeyboard_isKeyPressed(sfKeyEnter));
    sfRenderWindow_clear(win_settings.window, sfBlack);
    sfRenderWindow_display(win_settings.window);
    while (!sfKeyboard_isKeyPressed(sfKeyEnter)) {
        if (!sfRenderWindow_isOpen(win_settings.window))
            return (sfFalse);
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            return (sfFalse);
        if (sfRenderWindow_pollEvent(win_settings.window, &event) && event.type == sfEvtClosed)
            return (sfFalse);
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