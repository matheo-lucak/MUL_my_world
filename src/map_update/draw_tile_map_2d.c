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
    if (selection && sets->mouse_tool.hold
        && sets->mode.edit_mode == TEXTURE_MODE) {
        ter->tile_map_2d[y][x].matter_state = sets->mode.matter;
        sets->mode.edit_repeat = 0;
    }
    assert_tile(sets->window, &(ter->tile_map_2d[y][x]), sets->mode);
}

static void order_draw_border(win_settings_t *sets, map_formatter_t *ter,
                                const sfBool order)
{
    const sfBool right_selected = ter->view_side == RIGHT ? 1 : 0;
    const sfBool left_selected = ter->view_side == LEFT ? 1 : 0;
    const sfBool top_selected = ter->view_side == TOP ? 1 : 0;
    const sfBool bottom_selected = ter->view_side == BOTTOM ? 1 : 0;

    if (!(order ^ right_selected))
        sfRenderWindow_drawVertexArray(sets->window, ter->borders[6], NULL);
    if (!(order ^ left_selected))
        sfRenderWindow_drawVertexArray(sets->window, ter->borders[7], NULL);
    if (!(order ^ top_selected)) {
        sfRenderWindow_drawVertexArray(sets->window, ter->borders[0], NULL);
        sfRenderWindow_drawVertexArray(sets->window, ter->borders[1], NULL);
        sfRenderWindow_drawVertexArray(sets->window, ter->borders[2], NULL);
    }
    if (!(order ^ bottom_selected)) {
        sfRenderWindow_drawVertexArray(sets->window, ter->borders[3], NULL);
        sfRenderWindow_drawVertexArray(sets->window, ter->borders[4], NULL);
        sfRenderWindow_drawVertexArray(sets->window, ter->borders[5], NULL);
    }
}

void draw_tile_map_2d(win_settings_t *sets, map_formatter_t *ter)
{
    register int x = 0;
    register int y = 0;

    order_draw_border(sets, ter, sfFalse);
    while (y < ter->map_settings.size.y) {
        for (x = 0; x < ter->map_settings.size.x; x += 1) {
            draw_vertex(sets, ter, y, x);
            draw_circle(sets, ter, (sfVector2i){x, y});
        }
        y += 1;
    }
    order_draw_border(sets, ter, sfTrue);
}