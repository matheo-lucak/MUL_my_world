/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Main instance of the game.
*/

#include "my.h"
#include "my_world.h"
#include "vector_engine.h"

static void draw_fps(win_settings_t win_settings, fps_assets_t *resources_fps)
{
    static int fps_counter = 0;
    static char fps_string[20];
    static int first_call = 0;

    if (!first_call) {
        my_strcpy(fps_string, "FPS: 0");
        fps_string[19] = '\0';
        sfText_setString(resources_fps->fps_drawer, fps_string);
        first_call = 1;
    }
    if (!resources_fps || !(resources_fps->clock))
        return ;
    fps_counter += 1;
    if (sfTime_asSeconds(sfClock_getElapsedTime(resources_fps->clock)) > 1) {
        my_strcpy(fps_string + 5, my_int_to_str(fps_counter));
        fps_counter = 0;
        sfClock_restart(resources_fps->clock);
        sfText_setString(resources_fps->fps_drawer, fps_string);
    }
    sfText_setPosition(resources_fps->fps_drawer, win_settings.anchor.topright);
    sfText_move(resources_fps->fps_drawer, vec2f(win_settings.scale.x * -(sfText_getLocalBounds(resources_fps->fps_drawer).width), 0));
    sfText_setScale(resources_fps->fps_drawer, win_settings.scale);
    sfRenderWindow_drawText(win_settings.window, resources_fps->fps_drawer, NULL);
}

void my_world(void)
{ 
    map_formatter_t terraformer;
    win_settings_t win_settings;
    fps_assets_t resources_fps;

    if (!init_game_structures(&win_settings, &terraformer, &resources_fps))
        return ;
    while (should_stay_opened(win_settings.window, &win_settings.event)) {
        sfRenderWindow_clear(win_settings.window, sfBlack);
        sfText_setPosition(resources_fps.fps_drawer, vec2f(0, 0));
        window_update(&win_settings, &terraformer, &resources_fps);
        draw_fps(win_settings, &resources_fps);
        sfRenderWindow_display(win_settings.window);
        }   
    free_game_structures(&win_settings, &terraformer, &resources_fps);
}