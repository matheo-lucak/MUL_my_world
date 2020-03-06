/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Updates the my_world 2d map
*/

#include "my.h"
#include "map_update.h"
#include "my_world.h"
#include "vector_engine.h"

void fill_vertex(const sfVector2f point, sfVertexArray *shape_drawer,
                    const sfVector2f tex_anchor)
{
    sfVertex voxel = {.position = point,
                    .color = sfWhite,
                    .texCoords = tex_anchor};

    sfVertexArray_append(shape_drawer, voxel);
}

void update_tile(tile_t *tile, map_formatter_t *ter, const sfVector2i pos)
{
    if (!tile)
        return ;
    sfVertexArray_clear(tile->shape_drawer);
    if (ter->textures && ter->textures[tile->matter_state])
        tile->rstate.texture = ter->textures[tile->matter_state];
    if (ter->shaders && ter->shaders[tile->matter_state])
        tile->rstate.shader = ter->shaders[tile->matter_state];
    fill_vertex(ter->map_2d[pos.y][pos.x], tile->shape_drawer, vec2f(0, 0));
    fill_vertex(ter->map_2d[pos.y][pos.x + 1], tile->shape_drawer,
                                vec2f(0, 1));
    fill_vertex(ter->map_2d[pos.y + 1][pos.x + 1], tile->shape_drawer,
                                vec2f(1, 1));
    fill_vertex(ter->map_2d[pos.y + 1][pos.x], tile->shape_drawer,
                                vec2f(1, 0));
    sfVertexArray_setPrimitiveType(tile->shape_drawer, sfQuads);
}

void update_tile_map_2d(map_formatter_t *ter)
{
    register int x = 0;
    register int y = 0;

    if (!ter)
        return;
    while (y < ter->map_settings.size.y - 1) {
        for (x = 0; x < ter->map_settings.size.x - 1; x += 1)
            update_tile(&(ter->tile_map_2d[y][x]), ter, vec2i(x, y));
        y += 1;
    }
}

void update_map_2d(map_formatter_t *ter)
{
    register int x = 0;
    register int y = 0;
    sfVector3f pos_3d;
    sfVector2i map_size;
    sfVector2i angles;

    if (!ter)
        return;
    map_size = ter->map_settings.size;
    angles = ter->map_settings.angles;
    while (y < ter->map_settings.size.y) {
        for (x = 0; x < ter->map_settings.size.x; x += 1) {
            pos_3d = (sfVector3f){x, y, ter->map_3d[y][x]};
            ter->map_2d[y][x] = project_iso_point(pos_3d, map_size, angles);
        }
        y += 1;
    }
}