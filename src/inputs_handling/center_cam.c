/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** center_cam
*/

#include "my_world.h"
#include "vector_engine.h"

static sfBool is_outside_view(win_settings_t *sets, sfVector2f **map,
                                                        sfVector2i size)
{
    sfFloatRect window_area = {0, 0, sets->size.x, sets->size.y};
    sfVector2i tmp_point = {0, 0};

    tmp_point = sfRenderWindow_mapCoordsToPixel(sets->window,
                                                map[0][0], sets->view);
    if (!sfFloatRect_contains(&window_area, tmp_point.x, tmp_point.y))
        return (sfFalse);
    tmp_point = sfRenderWindow_mapCoordsToPixel(sets->window,
                                                map[size.y][0], sets->view);
    if (!sfFloatRect_contains(&window_area, tmp_point.x, tmp_point.y))
        return (sfFalse);
    tmp_point = sfRenderWindow_mapCoordsToPixel(sets->window,
                                                map[0][size.x], sets->view);
    if (!sfFloatRect_contains(&window_area, tmp_point.x, tmp_point.y))
        return (sfFalse);
    tmp_point = sfRenderWindow_mapCoordsToPixel(sets->window,
                                        map[size.y][size.x], sets->view);
    if (!sfFloatRect_contains(&window_area, tmp_point.x, tmp_point.y))
        return (sfFalse);
    return (sfTrue);
}

sfBool center_cam(win_settings_t *sets, map_formatter_t *ter)
{
    sfVector2f center = {0, 0};
    sfVector2i size = ter->map_settings.size;

    if (!sfKeyboard_isKeyPressed(sfKeyC))
        return (sfFalse);
    size = vec2i(size.x - 1, size.y - 1);
    if (size.x < 0 || size.y < 0)
        return (sfFalse);
    center.x = (ter->map_2d[size.y][size.x].x + ter->map_2d[0][0].x) / 2;
    center.y = (ter->map_2d[size.y][size.x].y + ter->map_2d[0][0].y) / 2;
    sfView_setCenter(sets->view, center);
    while (!is_outside_view(sets, ter->map_2d, size))
        sfView_zoom(sets->view, 1.001);
    do {
        sfView_zoom(sets->view, 0.999);
    } while (is_outside_view(sets, ter->map_2d, size));
    return (sfTrue);
}