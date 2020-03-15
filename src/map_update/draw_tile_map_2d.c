/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_v_map_2d
*/

#include "my.h"
#include "my_world.h"
#include "my_graphical.h"
#include "vector_engine.h"

static void assert_tile(sfRenderWindow *win, tile_t *tile,
                            const game_mode_t mode)
{
    if (is_view_mode(mode, VIEW_TEXTURE)) {
        sfRenderWindow_drawVertexArray(win, tile->shape_drawer,
                                        &(tile->rstate));
    }
    if (is_view_mode(mode, VIEW_LINE)) {
        sfVertexArray_setPrimitiveType(tile->shape_drawer, sfLinesStrip);
        sfRenderWindow_drawVertexArray(win, tile->shape_drawer, NULL);
    }
    sfVertexArray_setPrimitiveType(tile->shape_drawer, sfQuads);
}

static void flatten_tile(win_settings_t *sets, map_formatter_t *ter,
                        const int y, const int x)
{
    static float height = 0;
    static sfBool tile_selected = sfFalse;

    if (!(sets->mouse_tool.hold)) {
        tile_selected = sfFalse;
    }
    if (sets->mouse_tool.click) {
        tile_selected = sfTrue;
        height = ter->map_3d[y][x];
    }
    if (tile_selected) {
        ter->map_3d[y][x] = height;
        ter->map_3d[y][x + 1] = height;
        ter->map_3d[y + 1][x] = height;
        ter->map_3d[y + 1][x + 1] = height;
    }
}

static void draw_vertex(win_settings_t *sets, map_formatter_t *ter,
                        const int y, const int x)
{
    sfFloatRect hitbox;
    sfBool selection = sfFalse;

    if (ter->map_settings.size.x - 1 == x || ter->map_settings.size.y - 1 == y)
        return;
    hitbox = sfVertexArray_getBounds(ter->tile_map_2d[y][x].shape_drawer);
    selection = sfFloatRect_contains(&hitbox, sets->mouse_tool.pos.x,
                                        sets->mouse_tool.pos.y);
    if (selection && sets->mouse_tool.hold) {
        if (sets->mode.edit_mode == TEXTURE_MODE) {
            ter->tile_map_2d[y][x].matter_state = sets->mode.matter;
            sets->mode.edit_repeat = 0;
        } else if (sets->mode.edit_mode == PIXEL_MODE
            && sets->mode.draw_mode == SPATULA_DRAW)
            flatten_tile(sets, ter, y, x);
    }
    assert_tile(sets->window, &(ter->tile_map_2d[y][x]), sets->mode);
}

void draw_tile_map_2d(win_settings_t *sets,
                        map_formatter_t *ter)
{
    register int x = 0;
    register int y = 0;

    while (y < ter->map_settings.size.y) {
        for (x = 0; x < ter->map_settings.size.x; x += 1) {
            draw_vertex(sets, ter, y, x);
            draw_circle(sets, ter, (sfVector2i){x, y});
        }
        y += 1;
    }
}