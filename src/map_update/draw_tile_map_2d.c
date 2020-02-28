/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_v_map_2d
*/

#include "my.h"
#include "my_world.h"
#include "my_graphical.h"

void draw_vertex(win_settings_t *win_settings, map_formatter_t *terraformer,
                                                        int y, int x)
{
    sfFloatRect hit_box;

    if (terraformer->map_settings.size.x - 1 == x ||
        terraformer->map_settings.size.y - 1 == y)
        return ;
    hit_box = sfVertexArray_getBounds(terraformer->tile_map_2d[y][x].shape_drawer);
    if (sfFloatRect_contains(&hit_box, win_settings->mouse_tool.pos.x, win_settings->mouse_tool.pos.y) && win_settings->mouse_tool.hold) {
        
        terraformer->tile_map_2d[y][x].matter_state = 3;

    }
    if (is_view_mode(win_settings->mode, VIEW_TEXTURE)) {
        sfRenderWindow_drawVertexArray
            (win_settings->window, terraformer->tile_map_2d[y][x].shape_drawer,
            &(terraformer->tile_map_2d[y][x].rstate));
    }
    if (is_view_mode(win_settings->mode, VIEW_LINE)) {
        sfVertexArray_setPrimitiveType(
            terraformer->tile_map_2d[y][x].shape_drawer, sfLinesStrip);
        sfRenderWindow_drawVertexArray
            (win_settings->window, terraformer->tile_map_2d[y][x].shape_drawer,
            NULL);
    }
    sfVertexArray_setPrimitiveType(terraformer->tile_map_2d[y][x].shape_drawer, sfQuads);
}

void draw_tile_map_2d(win_settings_t *win_settings,
                        map_formatter_t *terraformer)
{
    int x = 0;
    int y = 0;

    while (y < terraformer->map_settings.size.y) {
        for (x = 0; x < terraformer->map_settings.size.x; x += 1) {
            draw_vertex(win_settings, terraformer, y, x);
            draw_circle(win_settings, terraformer, (sfVector2i){x, y});
        }
        y += 1;
    }
}