/*
** EPITECH PROJECT, 2019
** MUL_my_world_boostrap_2019
** File description:
** draws an array of sfVector2f onto the window
*/

#include "my_world.h"

static void draw_line(sfVector2f *point1, sfVector2f *point2,
                        sfVector2f *point3, sfRenderWindow *window)
{
    sfVertexArray *vertex_lims = NULL;

    vertex_lims = create_line(point1, point2, point3, sfWhite);
    sfVertexArray_setPrimitiveType(vertex_lims, sfTriangles);
    sfRenderWindow_drawVertexArray(window, vertex_lims, NULL);
    vertex_lims = create_line(point1, point2, point3, sfBlack);
    sfVertexArray_setPrimitiveType(vertex_lims, sfLineStrip);
    sfRenderWindow_drawVertexArray(window, vertex_lims, NULL);
    if (vertex_lims)
        sfVertexArray_destroy(vertex_lims);
}

static void draw_both_lines(sfRenderWindow *window, map_settings_t presets,
                            sfVector2f **map_2d, sfVector2i pos)
{
    draw_line(&map_2d[pos.y][pos.x], &map_2d[pos.y + 1][pos.x],
            &map_2d[pos.y + 1][pos.x + 1], window);
    draw_line(&map_2d[pos.y][pos.x], &map_2d[pos.y][pos.x + 1],
            &map_2d[pos.y + 1][pos.x + 1], window);
}

void draw_2d_map(sfRenderWindow *window, map_settings_t presets,
                sfVector2f **map_2d)
{
    int x = 0;
    int y = 0;

    while (y < presets.map_height - 1) {
        for (x = 0; x < presets.map_width - 1; x += 1)
            draw_both_lines(window, presets, map_2d, (sfVector2i){x, y});
        y += 1;
    }
}