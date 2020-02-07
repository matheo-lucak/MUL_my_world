/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** controls the camera view onto the 3D scene.
*/

#include <SFML/Graphics.h>

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
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        sfView_zoom(view, 0.98);
    sfRenderWindow_setView(window, view);
}