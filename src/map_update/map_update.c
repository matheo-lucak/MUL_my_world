/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_update
*/

#include "my.h"
#include "map_update.h"
#include "my_world.h"

void fill_vertex(sfVector2f point, sfVertexArray *shape_drawer, sfVector2f tex_anchor)
{
    sfVector2f point_resized = (sfVector2f) {point.x * 100, point.y * 100};
    sfVertex voxel = {.position = point_resized, .color = sfRed, .texCoords = tex_anchor};

    sfVertexArray_append(shape_drawer, voxel);
}
void update_tile(tile_t *tile, map_formatter_t *terraformer,
                                            sfVector2i pos)
{
    if (!tile)
        return ;
    if (terraformer->map_3d[pos.y][pos.x] > 25 && terraformer->map_3d[pos.y][pos.x] < 40) {
        tile->matter_state = STONE;
    } else if (terraformer->map_3d[pos.y][pos.x] > 40) {
        tile->matter_state = SNOW;
    } else {
        tile->matter_state = GRASS;
    }
    sfVertexArray_clear(tile->shape_drawer);
    if (terraformer->textures && terraformer->textures[tile->matter_state])
        tile->rstate.texture = terraformer->textures[tile->matter_state];
    if (terraformer->shaders && terraformer->shaders[0]) {
        tile->rstate.shader = terraformer->shaders[0];
    }
    fill_vertex(terraformer->map_2d[pos.y][pos.x], tile->shape_drawer, (sfVector2f){0, 0});
    fill_vertex(terraformer->map_2d[pos.y][pos.x + 1], tile->shape_drawer, (sfVector2f){0, 1});
    fill_vertex(terraformer->map_2d[pos.y + 1][pos.x + 1], tile->shape_drawer, (sfVector2f){1, 1});
    fill_vertex(terraformer->map_2d[pos.y + 1][pos.x], tile->shape_drawer, (sfVector2f){1, 0});
    sfVertexArray_setPrimitiveType(tile->shape_drawer, sfQuads);
}

void update_tile_map_2d(map_formatter_t *terraformer)
{
    int x = 0;
    int y = 0;

    if (!terraformer)
        return;
    while (y < terraformer->map_settings.size.y - 1) {
        for (x = 0; x < terraformer->map_settings.size.x - 1; x += 1) {
            update_tile(&(terraformer->tile_map_2d[y][x]), terraformer,
                                                    (sfVector2i){x, y});
        }
        y += 1;
    }
}

void update_map_2d(map_formatter_t *terraformer)
{
    sfVector3f pos_3d;
    int x = 0;
    int y = 0;

    if (!terraformer)
        return ;
    while (y < terraformer->map_settings.size.y) {
        for (x = 0; x < terraformer->map_settings.size.x; x += 1) {
            pos_3d = (sfVector3f){x, y, terraformer->map_3d[y][x]};
            terraformer->map_2d[y][x] = project_iso_point(pos_3d,
                                            terraformer->map_settings.size,
                                            terraformer->map_settings.angles);
        }
        y += 1;
    }
}