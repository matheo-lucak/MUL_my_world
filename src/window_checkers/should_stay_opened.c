/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** should_stay_opened.c
*/

#include "my_world.h"

const sfBool should_stay_opened(sfRenderWindow *window)
{
    static sfEvent event;

    if (!sfRenderWindow_isOpen(window))
        return (sfFalse);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        return (sfFalse);
    if (sfRenderWindow_pollEvent(window, &event) && event.type == sfEvtClosed)
        return (sfFalse);
    return (sfTrue);
}