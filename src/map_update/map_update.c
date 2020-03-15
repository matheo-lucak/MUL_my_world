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
    fill_vertex(ter->map_2d[pos.y][pos.x + 1], tile->shape_drawer, vec2f(0, 1));
    fill_vertex(ter->map_2d[pos.y + 1][pos.x + 1], tile->shape_drawer, vec2f(1, 1));
    fill_vertex(ter->map_2d[pos.y + 1][pos.x], tile->shape_drawer, vec2f(1, 0));
    fill_vertex(ter->map_2d[pos.y][pos.x], tile->shape_drawer, vec2f(0, 0));
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

    if (!ter)
        return;
    while (y < ter->map_settings.size.y) {
        for (x = 0; x < ter->map_settings.size.x; x += 1)
            ter->map_2d[y][x] = project_iso_point((sfVector3f){x, y,
                                                    ter->map_3d[y][x]},
                                                ter->map_settings.size,
                                                ter->map_settings.angles);
        y += 1;
    }
    for (int i = 0; i < 8; i += 1)
        sfVertexArray_clear(ter->borders[i]);
    fill_vertex(project_iso_point((sfVector3f){0, 0, -1}, ter->map_settings.size, ter->map_settings.angles), ter->borders[0], vec2f(0, 0));
    fill_vertex(project_iso_point((sfVector3f){0, 0, ter->map_3d[0][0]}, ter->map_settings.size, ter->map_settings.angles), ter->borders[0], vec2f(0, 0));
    fill_vertex(project_iso_point((sfVector3f){ter->map_settings.size.x - 1, 0, -1}, ter->map_settings.size, ter->map_settings.angles), ter->borders[1], vec2f(0, 0));
    fill_vertex(project_iso_point((sfVector3f){ter->map_settings.size.x - 1, 0, ter->map_3d[0][ter->map_settings.size.x - 1]}, ter->map_settings.size, ter->map_settings.angles), ter->borders[1], vec2f(0, 0));
    fill_vertex(project_iso_point((sfVector3f){0, 0, -1}, ter->map_settings.size, ter->map_settings.angles), ter->borders[2], vec2f(0, 0));
    fill_vertex(project_iso_point((sfVector3f){ter->map_settings.size.x - 1, 0, -1}, ter->map_settings.size, ter->map_settings.angles), ter->borders[2], vec2f(0, 0));
    fill_vertex(project_iso_point((sfVector3f){ter->map_settings.size.x - 1, ter->map_settings.size.y - 1, -1}, ter->map_settings.size, ter->map_settings.angles), ter->borders[3], vec2f(0, 0));
    fill_vertex(project_iso_point((sfVector3f){ter->map_settings.size.x - 1, ter->map_settings.size.y - 1, ter->map_3d[ter->map_settings.size.y - 1][ter->map_settings.size.x - 1]}, ter->map_settings.size, ter->map_settings.angles), ter->borders[3], vec2f(0, 0));
    fill_vertex(project_iso_point((sfVector3f){0, ter->map_settings.size.y - 1, -1}, ter->map_settings.size, ter->map_settings.angles), ter->borders[4], vec2f(0, 0));
    fill_vertex(project_iso_point((sfVector3f){0, ter->map_settings.size.y - 1, ter->map_3d[ter->map_settings.size.y - 1][0]}, ter->map_settings.size, ter->map_settings.angles), ter->borders[4], vec2f(0, 0));
    fill_vertex(project_iso_point((sfVector3f){ter->map_settings.size.x - 1, ter->map_settings.size.y - 1, -1}, ter->map_settings.size, ter->map_settings.angles), ter->borders[4], vec2f(0, 0));
    fill_vertex(project_iso_point((sfVector3f){0, ter->map_settings.size.y - 1, -1}, ter->map_settings.size, ter->map_settings.angles), ter->borders[4], vec2f(0, 0));
    fill_vertex(project_iso_point((sfVector3f){ter->map_settings.size.x - 1, 0, -1}, ter->map_settings.size, ter->map_settings.angles), ter->borders[6], vec2f(0, 0));
    fill_vertex(project_iso_point((sfVector3f){ter->map_settings.size.x - 1, ter->map_settings.size.y - 1, -1}, ter->map_settings.size, ter->map_settings.angles), ter->borders[6], vec2f(0, 0));
    fill_vertex(project_iso_point((sfVector3f){0, 0, -1}, ter->map_settings.size, ter->map_settings.angles), ter->borders[7], vec2f(0, 0));
    fill_vertex(project_iso_point((sfVector3f){0, ter->map_settings.size.y - 1, -1}, ter->map_settings.size, ter->map_settings.angles), ter->borders[7   ], vec2f(0, 0));
}