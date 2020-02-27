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

void print_fps(void)
{
    static sfClock *clock = NULL;
    static int frame = 0;
    sfTime time;

    if (!clock)
        clock = sfClock_create();
    if (clock) {
        time = sfClock_getElapsedTime(clock);
        frame += 1;
        if (sfTime_asSeconds(time) > 1) {
            my_printf("FPS: %d\n", frame);
            sfClock_restart(clock);
            frame = 0;
        }
    }
}

void my_world(void)
{ 
    map_linked_list_t *my_map = NULL;
    map_formatter_t terraformer;
    win_settings_t win_settings;

    if (!init_game_structures(&win_settings, &terraformer))
        return;
    while (should_stay_opened(win_settings.window)) {
        sfRenderWindow_clear(win_settings.window, sfBlack);
        update_mouse_tool(&win_settings);
        control_camera_view(terraformer.map_settings, win_settings);
        if (control_angle_view(&(terraformer.map_settings)) ||
            win_settings.mouse_tool.hold) {
            update_map_2d(&terraformer);
            update_tile_map_2d(&terraformer);
        }
        draw_tile_map_2d(&win_settings, &terraformer);
        sfRenderWindow_display(win_settings.window);
        print_fps();
    }
    free_game_structures(&win_settings, &terraformer, &my_map);
}