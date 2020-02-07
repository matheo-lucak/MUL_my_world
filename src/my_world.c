/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Main instance of the game.
*/

#include <stdlib.h>
#include <time.h>
#include "my_world.h"

static int is_to_be_closed(sfRenderWindow *window)
{
    static sfEvent event;

    if (!sfRenderWindow_isOpen(window))
        return (0);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        return (0);
    if (sfRenderWindow_pollEvent(window, &event) && event.type == sfEvtClosed)
        return (0);
    return (1);
}

int my_world(void)
{
    win_settings_t win_sets = init_window();
    map_t world_map = init_world_map();

    srand(time(0));
    while (is_to_be_closed(win_sets.window)) {
        sfRenderWindow_clear(win_sets.window, sfBlack);
        draw_2d_map(win_sets.window, world_map.presets, world_map.map_2d);
        control_window_view(win_sets.window, win_sets.view);
        sfRenderWindow_display(win_sets.window);
        if (sfKeyboard_isKeyPressed(sfKeyH)) {
            free(world_map.map_2d);
            world_map.presets.angle_y -= 1;
            world_map.map_2d = create_2d_map(world_map.presets, world_map.not_edited);
        }
        if (sfKeyboard_isKeyPressed(sfKeyY)) {
            free(world_map.map_2d);
            world_map.presets.angle_y += 1;
            world_map.map_2d = create_2d_map(world_map.presets, world_map.not_edited);
        }
        if (sfKeyboard_isKeyPressed(sfKeyG)) {
            free(world_map.map_2d);
            world_map.presets.angle_x -= 1;
            world_map.map_2d = create_2d_map(world_map.presets, world_map.not_edited);
        }
        if (sfKeyboard_isKeyPressed(sfKeyJ)) {
            free(world_map.map_2d);
            world_map.presets.angle_x += 1;
            world_map.map_2d = create_2d_map(world_map.presets, world_map.not_edited);
        }
    }
    free_win_sets(&win_sets);
    free_world_map(&world_map);
    return (0);
}