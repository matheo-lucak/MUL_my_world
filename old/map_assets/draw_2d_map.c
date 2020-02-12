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
    static sfTexture *texture = NULL;
    static sfShader *shader = NULL;
    static sfRenderStates rd;
    sfVertexArray *vertex_lims = NULL;
    sfFloatRect bounds;

    if (!texture || !shader) {
        texture = sfTexture_createFromFile("rock.png", NULL);
        shader = sfShader_createFromFile("shader2.vert", NULL, "shader.frag");
        sfShader_setTextureUniform(shader, "tex", texture);
        sfShader_setVec2Uniform(shader, "scale", (sfGlslVec2){0.01, 0.01});
        rd.shader = shader;
        rd.blendMode = sfBlendAlpha;
        rd.transform = sfTransform_Identity; 
        rd.texture = texture;
    }
    vertex_lims = create_line(point1, point2, point3, sfBlack);
    bounds = sfVertexArray_getBounds(vertex_lims);
    printf("%f %f %f %f\n", bounds.left, bounds.top, bounds.left + bounds.width, bounds.top - bounds.height);
    sfVertexArray_setPrimitiveType(vertex_lims, sfTriangles);
    sfRenderWindow_drawVertexArray(window, vertex_lims, &rd);
    sfVertexArray_setPrimitiveType(vertex_lims, sfLinesStrip);
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