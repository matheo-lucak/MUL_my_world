/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** center_cam
*/

#include "my_world.h"
#include "vector_engine.h"

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
    return (sfTrue);
}