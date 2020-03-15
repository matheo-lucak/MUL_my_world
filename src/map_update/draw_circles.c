/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Draws all of the pins.
*/

#include "my.h"
#include "my_world.h"
#include "my_graphical.h"
#include "vector_engine.h"

static sfBool point_on_circle(sfCircleShape *circle, sfVector2f point)
{
    static sfFloatRect box;

    box = sfCircleShape_getGlobalBounds(circle);
    if (sfFloatRect_contains(&box, point.x, point.y))
        return (sfTrue);
    return (sfFalse);
}

static void set_green_update(win_settings_t sets, float *map_tile,
                            sfCircleShape *circle, const float z_offset)
{
    sfCircleShape_setFillColor(circle, sfGreen);
    *map_tile = sets.mouse_tool.click_pos.y - sets.mouse_tool.pos.y + z_offset;
    magnet_number(map_tile, 0.2, 100, 1);
}

static void check_circle_selected(win_settings_t sets, map_formatter_t *ter,
                                sfCircleShape *circle, const sfVector2i pos)
{
    static sfVector2i saved_pos = {-1, -1};
    static sfBool selected_point = sfFalse;
    static float z_offset = 0;
    sfBool is_on_circle = point_on_circle(circle, sets.mouse_tool.pos);

    if (is_on_circle && !selected_point) {
        sfCircleShape_setFillColor(circle, sfYellow);
        if (sets.mouse_tool.hold) {
            saved_pos = pos;
            selected_point = sfTrue;
            z_offset = ter->map_3d[pos.y][pos.x];
        }
    } else
        sfCircleShape_setFillColor(circle, sfBlue);
    if (selected_point && pos.x == saved_pos.x && pos.y == saved_pos.y
        && sets.mode.edit_mode == PIXEL_MODE
        && sets.mode.draw_mode == PIXEL_DRAW)
        set_green_update(sets, &(ter->map_3d[pos.y][pos.x]), circle, z_offset);
    if (!sets.mouse_tool.hold)
        selected_point = sfFalse;
}

void draw_circle(win_settings_t *sets, map_formatter_t *ter,
                    const sfVector2i pos)
{
    static sfCircleShape *circle = NULL;

    if (!sets || !ter)
        return ;
    if (!is_view_mode(sets->mode, VIEW_PIN))
        return;
    if (!circle) {
        circle = sfCircleShape_create();
        sfCircleShape_setRadius(circle, 0.1);
        sfCircleShape_setOrigin(circle, vec2f(0.1, 0.1));
    }
    sfCircleShape_setPosition(circle, ter->map_2d[pos.y][pos.x]);
    check_circle_selected(*sets, ter, circle, pos);
    sfRenderWindow_drawCircleShape(sets->window, circle, NULL);
}