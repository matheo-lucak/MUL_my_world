/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_v_map_2d
*/

#include "my.h"
#include "my_world.h"
#include "my_graphical.h"

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
    if (selection && sets->mouse_tool.hold)
        ter->tile_map_2d[y][x].matter_state = SAND;
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