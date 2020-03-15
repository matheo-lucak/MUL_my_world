/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** apply_biomes
*/

#include "my_world.h"
#include "map_update.h"
#include "map_generation.h"

static void apply_altitude(map_formatter_t *ter, int x, int y)
{
    float average = 0;

    if (!ter || !(ter->map_3d) || !(ter->map_3d[y]))
        return ;
    average += ter->map_3d[y][x];
    average += ter->map_3d[y + 1][x];
    average += ter->map_3d[y][x + 1];
    average += ter->map_3d[y + 1][x + 1];
    average /= 4;
    if (average > 25 && average < 40) {
        ter->tile_map_2d[y][x].matter_state = STONE;
    } else if (average > 40) {
        ter->tile_map_2d[y][x].matter_state = SNOW;
    } else {
        ter->tile_map_2d[y][x].matter_state = GRASS;
    }
}

void apply_biomes(map_formatter_t *ter)
{
    int x = 0;
    int y = 0;

    while (y < ter->map_settings.size.y - 1) {
        for (x = 0; x < ter->map_settings.size.x - 1; x += 1) {
            apply_altitude(ter, x, y);
        }
        y += 1;
    }
}
