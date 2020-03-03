/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** should_stay_opened.c
*/

#include "my_world.h"

sfBool should_stay_opened(sfRenderWindow *window, sfEvent *event, sfBool *goback_menu)
{
    if (!sfRenderWindow_isOpen(window))
        return (sfFalse);
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        *goback_menu = sfTrue;
        return (sfFalse);
    }
    if (sfRenderWindow_pollEvent(window, event) && event->type == sfEvtClosed)
        return (sfFalse);
    return (sfTrue);
}