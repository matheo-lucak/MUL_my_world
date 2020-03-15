/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Updates the borders drawing sequence.
*/

#include "map_update.h"
#include "vector_engine.h"
#include "my_world.h"

static void update_north_border(float **map, const sfVector2i size,
                                const sfVector2i angles,
                                sfVertexArray *borders[7])
{
    fill_vertex(project_iso_point(vec3f(0, 0, -1), size, angles),
                                    borders[0], vec2f(0, 0));
    fill_vertex(project_iso_point(vec3f(0, 0, map[0][0]), size, angles),
                                    borders[0], vec2f(0, 0));
    fill_vertex(project_iso_point(vec3f(size.x - 1, 0, -1), size, angles),
                                    borders[1], vec2f(0, 0));
    fill_vertex(project_iso_point(vec3f(size.x - 1, 0, map[0][size.x - 1]),
                                    size, angles),
                                    borders[1], vec2f(0, 0));
    fill_vertex(project_iso_point(vec3f(0, 0, -1), size, angles),
                                    borders[2], vec2f(0, 0));
    fill_vertex(project_iso_point(vec3f(size.x - 1, 0, -1),
                                    size, angles),
                                    borders[2], vec2f(0, 0));
}

static void update_south_border(float **map, const sfVector2i size,
                                const sfVector2i angles,
                                sfVertexArray *borders[7])
{
    fill_vertex(project_iso_point(vec3f(size.x - 1, size.y - 1, -1),
                                    size, angles),
                                    borders[3], vec2f(0, 0));
    fill_vertex(project_iso_point(vec3f(size.x - 1, size.y - 1,
                                    map[size.y - 1][size.x - 1]),
                                    size, angles),
                                    borders[3], vec2f(0, 0));
    fill_vertex(project_iso_point(vec3f(0, size.y - 1, -1),
                                    size, angles),
                                    borders[4], vec2f(0, 0));
    fill_vertex(project_iso_point(vec3f(0, size.y - 1, map[size.y - 1][0]),
                                    size, angles),
                                    borders[4], vec2f(0, 0));
    fill_vertex(project_iso_point(vec3f(size.x - 1, size.y - 1, -1),
                                    size, angles),
                                    borders[4], vec2f(0, 0));
    fill_vertex(project_iso_point(vec3f(0, size.y - 1, -1),
                                    size, angles),
                                    borders[4], vec2f(0, 0));
}

static void update_right_border(const sfVector2i size,
                                const sfVector2i angles,
                                sfVertexArray *borders[7])
{
    fill_vertex(project_iso_point(vec3f(size.x - 1, 0, -1),
                                    size, angles),
                                    borders[6], vec2f(0, 0));
    fill_vertex(project_iso_point(vec3f(size.x - 1, size.y - 1, -1),
                                    size, angles),
                                    borders[6], vec2f(0, 0));
}

static void update_left_border(const sfVector2i size,
                                const sfVector2i angles,
                                sfVertexArray *borders[7])
{
    fill_vertex(project_iso_point(vec3f(0, 0, -1), size, angles),
                                    borders[7], vec2f(0, 0));
    fill_vertex(project_iso_point(vec3f(0, size.y - 1, -1), size, angles),
                                    borders[7], vec2f(0, 0));
}

void update_border(float **map, const sfVector2i size, const sfVector2i angles,
                    sfVertexArray *borders[7])
{
    register size_t index = 0;

    while (index < 8) {
        sfVertexArray_clear(borders[index]);
        index += 1;
    }
    update_north_border(map, size, angles, borders);
    update_south_border(map, size, angles, borders);
    update_right_border(size, angles, borders);
    update_left_border(size, angles, borders);
}