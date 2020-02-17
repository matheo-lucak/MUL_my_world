/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_update
*/

#include "map_update.h"
#include "my_world.h"

void update_vertex_array(sfVector2i pos, sfVector2f** map_2d, sfVertexArray* vertex_array)
{
    sfVertexArray_clear(vertex_array);
}

void update_v_map_2d(map_formatter_t *terraformer)
{
    int x = 0;
    int y = 0;

    if (!terraformer)
        return ;
    while (y < terraformer->map_settings.map_y - 1) {
        while (x < terraformer->map_settings.map_y - 1) {
            update_vertex_array((sfVector2i){x, y}, terraformer->map_2d,
                                            terraformer->v_map_2d[y][x]);
            x += 1;
        }
        x = 0;
        y += 1;
    }
}

void update_map_2d(map_formatter_t *terraformer)
{
    sfVector3f pos_3d;
    sfVector2f map_size;
    sfVector2i map_angles;
    int y = 0;
    int x = 0;

    if (!terraformer)
        return (NULL);
    map_size = (sfVector2f){terraformer->map_settings.map_x,
                            terraformer->map_settings.map_y};
    map_angles = (sfVector2i){terraformer->map_settings.angle_x,
                                terraformer->map_settings.angle_x};
    while (y < terraformer->map_settings.map_y) {
        while (x < terraformer->map_settings.map_x) {
            pos_3d = (sfVector3f) {x, y, terraformer->map_3d[y][x]};
            terraformer->map_2d[y][x] = project_iso_point(pos_3d, map_size,
                                                            map_angles);
            x++;
        }
        y++;
        x = 0;
    }
}