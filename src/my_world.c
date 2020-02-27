/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Main instance of the game.
*/

#include "my.h"
#include "my_world.h"
#include "input_handling.h"
#include "map_update.h"

static void print_fps(sfRenderWindow *window, fps_assets_t *resources_fps)
{
    resources_fps->time = sfClock_getElapsedTime(resources_fps->clock);
    resources_fps->cur_fps += 1;
    if (sfTime_asSeconds(resources_fps->time) > 1) {
        sfClock_restart(resources_fps->clock);
        if (resources_fps->old_fps != resources_fps->cur_fps)
            sfText_setString(resources_fps->fps_drawer, resources_fps->my_fps);
        resources_fps->old_fps = resources_fps->cur_fps;
        resources_fps->cur_fps = 0;
    }
    //sfRenderWindow_drawText(window, resources_fps->fps_drawer, NULL);
}

void my_world(void)
{
    map_formatter_t terraformer;
    win_settings_t win_settings;
    fps_assets_t resources_fps;

    if (!init_game_structures(&win_settings, &terraformer, &resources_fps))
        return;
    while (should_stay_opened(win_settings.window, &win_settings.event)) {
        sfRenderWindow_clear(win_settings.window, sfBlack);
        //win_settings.size = sfRenderWindow_getSize(win_settings.window);
        update_mouse_tool(&win_settings);
        control_camera_view(terraformer.map_settings, win_settings, &resources_fps);
        if (control_angle_view(&(terraformer.map_settings)) || win_settings.mouse_tool.hold) {
            win_settings.center = sfView_getCenter(win_settings.view);
            update_map_2d(&terraformer);
            update_tile_map_2d(&terraformer);
        }
        draw_tile_map_2d(win_settings, &terraformer);
        print_fps(win_settings.window, &resources_fps);
        sfRenderWindow_display(win_settings.window);
    }   
    free_game_structures(&win_settings, &terraformer, &resources_fps);
}