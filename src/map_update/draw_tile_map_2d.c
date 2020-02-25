/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_v_map_2d
*/

#include "my.h"
#include "my_world.h"
#include "my_graphical.h"

void draw_vertex(sfRenderWindow *window, map_formatter_t *terraformer,
                                                        int y, int x)
{
    if (terraformer->map_settings.size.x -1 == x ||
        terraformer->map_settings.size.y -1 == y)
        return ;
    sfShader_setTextureUniform((sfShader *)
            (terraformer->tile_map_2d[y][x].rstate.shader), "tex",
            (sfTexture *)(terraformer->tile_map_2d[y][x].rstate.texture));
    sfShader_setVec2Uniform((sfShader *)
            (terraformer->tile_map_2d[y][x].rstate.shader),"scale",
            (sfGlslVec2){1, 1});
    sfRenderWindow_drawVertexArray
                (window, terraformer->tile_map_2d[y][x].shape_drawer,
                &(terraformer->tile_map_2d[y][x].rstate));
}

void draw_tile_map_2d(win_settings_t win_settings,
                        map_formatter_t *terraformer)
{
    int x = 0;
    int y = 0;

    while (y < terraformer->map_settings.size.y) {
        for (x = 0; x < terraformer->map_settings.size.x; x += 1) {
            draw_vertex(win_settings.window, terraformer, y, x);
            draw_circle(win_settings, terraformer, (sfVector2i){x, y});
        }
        y += 1;
    }
}