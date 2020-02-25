/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_circles
*/

#include "my.h"
#include "my_world.h"
#include "my_graphical.h"

static sfBool circle_contains_point(sfCircleShape *circle, sfVector2f point)
{
    static sfFloatRect box;

    box = sfCircleShape_getGlobalBounds(circle);
    if (sfFloatRect_contains(&box, point.x, point.y))
        return (sfTrue);
    return (sfFalse);
}

static void approximate_float(float *point, int min, int max)
{
    if (*point >= 0) {
        if ((int)(*point * 100) % 100 >= max) {
            *point += (float)(100 - (int)(*point * 100) % 100) / 100;
        } else if ((int)(*point * 100) % 100 <= min) {
            *point -= (float)((int)(*point * 100) % 100) / 100;
        }
        return ;
    }
    if (*point < 0) {
        if (-1 *((int)(*point * 100) % 100) >= max) {
            *point -= (float)(100 + (int)(*point * 100) % 100) / 100;
        } else if (-1 *((int)(*point * 100) % 100) <= min) {
            *point += (float)((int)(*point * -100) % 100) / 100;
        }
        return;
    }
}

static void check_circle_selected(win_settings_t win_settings,
                                map_formatter_t *terraformer,
                                sfCircleShape *circle, sfVector2i pos)
{
    static sfVector2i saved_pos = {-1, -1};
    static sfBool point_selected = 0;
    static float old_z = 0;

    sfCircleShape_setFillColor(circle, sfBlue);
    if (circle_contains_point(circle, win_settings.mouse_tool.pos) &&
        win_settings.mouse_tool.hold == 1 && !point_selected) {
        saved_pos = pos;
        point_selected = 1;
        old_z = terraformer->map_3d[pos.y][pos.x];
        sfCircleShape_setFillColor(circle, sfRed);
    }
    if (point_selected && pos.x == saved_pos.x && pos.y == saved_pos.y) {
        sfCircleShape_setFillColor(circle, sfGreen);
        terraformer->map_3d[saved_pos.y][saved_pos.x] = win_settings.mouse_tool.click_pos.y - win_settings.mouse_tool.pos.y + old_z;
        approximate_float(&(terraformer->map_3d[saved_pos.y][saved_pos.x]), 20, 80);
    }
    if (!win_settings.mouse_tool.hold)
        point_selected = 0;
}

void draw_circle(win_settings_t win_settings, map_formatter_t *terraformer,
                    sfVector2i pos)
{
    static sfCircleShape *circle = NULL;

    if (!circle) {
        circle = sfCircleShape_create();
        sfCircleShape_setRadius(circle, 0.1);
        sfCircleShape_setOrigin(circle, (sfVector2f){0.1, 0.1});
    }
    sfCircleShape_setPosition(circle, terraformer->map_2d[pos.y][pos.x]);
    check_circle_selected(win_settings, terraformer, circle, pos);
    sfRenderWindow_drawCircleShape(win_settings.window, circle, NULL);
}