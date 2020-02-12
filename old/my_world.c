/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Main instance of the game.
*/

#include <stdlib.h>
#include <stdio.h>
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
    sfVector2i m_pos;
    sfVector2f view_pos;
    sfVector2f final_pos;
    sfVector2u window_size;
    
    srand(time(0));
    while (is_to_be_closed(win_sets.window)) {
        window_size = sfRenderWindow_getSize(win_sets.window);
        m_pos = sfMouse_getPositionRenderWindow(win_sets.window);
        view_pos = sfView_getCenter(win_sets.view);
        final_pos.x = (m_pos.x - (float)window_size.x / 2) + view_pos.x;
        final_pos.y = (m_pos.y - (float)window_size.y / 2) + view_pos.y;
        printf("%f %f\n", final_pos.x, final_pos.y);
        sfRenderWindow_clear(win_sets.window, sfBlack);
        draw_2d_map(win_sets.window, world_map.presets, world_map.map_2d);
        control_window_view(win_sets.window, win_sets.view);
        control_map_view(&world_map);
        sfRenderWindow_display(win_sets.window);
    }
    free_win_sets(&win_sets);
    free_world_map(&world_map);
    return (0);
}