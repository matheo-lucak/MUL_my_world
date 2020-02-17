/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_update
*/

#include "my.h"
#include "map_update.h"
#include "my_world.h"

void fill_vertex(sfVector2f point, sfVertexArray *shape_drawer)
{
    sfVertex voxel = {.position = point, .color = sfRed, .tex}
}
void update_tile(tile_t *tile, const sfTexture **textures, sfVector2f **map_2d, sfVector2i pos)
{
    if (!tile)
        return (NULL);
    sfVertexArray_clear(tile->shape_drawer);
    if (textures && textures[tile->matter_state])
        tile->rstate.texture = textures[tile->matter_state];
    sfVertexArray_setPrimitiveType(tile->shape_drawer, sfQuads);
}

void update_tile_map_2d(map_formatter_t *terraformer)
{
    int x = 0;
    int y = 0;

    if (!terraformer)
        return;
    while (y < terraformer->map_settings.size.y - 1) {
        for (x = 0; x < terraformer->map_settings.size.x - 1; x += 1)
            update_tile(&(terraformer->tile_map_2d[y][x]), , , (sfVector2i){x, y});
        y += 1;
    }
}

void update_map_2d(map_formatter_t *terraformer)
{
    sfVector3f pos_3d;
    int x = 0;
    int y = 0;

    if (!terraformer)
        return (NULL);
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