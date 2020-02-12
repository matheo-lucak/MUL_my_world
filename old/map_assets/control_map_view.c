/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** controls the camera view onto the 3D scene.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_world.h"

void control_window_view(sfRenderWindow *window, sfView *view)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        sfView_move(view, (sfVector2f){10, 0});
    else if (sfKeyboard_isKeyPressed(sfKeyLeft))
        sfView_move(view, (sfVector2f){-10, 0});
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        sfView_move(view, (sfVector2f){0, -10});
    else if (sfKeyboard_isKeyPressed(sfKeyDown))
        sfView_move(view, (sfVector2f){0, 10});
    if (sfKeyboard_isKeyPressed(sfKeyA))
        sfView_zoom(view, 1.02);
    if (sfKeyboard_isKeyPressed(sfKeyE))
        sfView_zoom(view, 0.98);
    sfRenderWindow_setView(window, view);
}

void control_map_view(map_t *world_map)
{
    if (!sfKeyboard_isKeyPressed(sfKeyZ) &&
        !sfKeyboard_isKeyPressed(sfKeyQ) &&
        !sfKeyboard_isKeyPressed(sfKeyS) &&
        !sfKeyboard_isKeyPressed(sfKeyD)) {
        return ;
    }
    free(world_map->map_2d);
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        world_map->presets.angle_y -= 1;
    } else if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        world_map->presets.angle_y += 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        world_map->presets.angle_x -= 1;
    } else if (sfKeyboard_isKeyPressed(sfKeyD)) {
        world_map->presets.angle_x += 1;
    }
    world_map->map_2d = create_2d_map(world_map->presets, world_map->not_edited);
}