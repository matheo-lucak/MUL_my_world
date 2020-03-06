/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** init_win_settings.c
*/

#include "my_world.h"
#include "vector_engine.h"

static sfBool init_main_track(sfMusic **main_track)
{
    const char main_track_path[] = "assets/sounds/my_world_main_track.ogg";

    if (!main_track)
        return (sfFalse);
    *main_track = sfMusic_createFromFile(main_track_path);
    if (!*main_track)
        return (sfFalse);
    sfMusic_setVolume(*main_track, 75);
    sfMusic_setLoop(*main_track, sfTrue);
    sfMusic_play(*main_track);
    return (sfTrue);
}

sfBool init_win_settings(win_settings_t *sets)
{
    sets->video_mode = (sfVideoMode){1920, 1080, 32};
    sets->window = sfRenderWindow_create(sets->video_mode,
                        "My_world by Matheo Lucak & Guillaume Bogard-Coquard",
                        sfClose | sfDefaultStyle, NULL);
    if (!sets->window)
        return (sfFalse);
    sfRenderWindow_setFramerateLimit(sets->window, 60);
    sfRenderWindow_setMouseCursorVisible(sets->window, sfTrue);
    sets->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    if (!sets->view) {
        free_win_settings(*sets);
        return (sfFalse);
    }
    sfView_setCenter(sets->view, vec2f(0, 0));
    sets->mode.view_mode = VIEW_ALL;
    if (!init_main_track(&(sets->main_track))) {
        free_win_settings(*sets);
        return (sfFalse);
    }
    udpate_window_settings(sets);
    return (sfTrue);
}