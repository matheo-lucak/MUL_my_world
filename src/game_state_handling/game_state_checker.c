/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Checks whether the game should continue
*/

#include "my_world.h"

sfBool game_state_checker(sfRenderWindow *window, sfEvent *event,
                        sfBool *goback_menu)
{
    if (!sfRenderWindow_isOpen(window))
        return (sfFalse);
    if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
        *goback_menu = sfTrue;
        return (sfFalse);
    }
    if (sfRenderWindow_pollEvent(window, event) && event->type == sfEvtClosed)
        return (sfFalse);
    return (sfTrue);
}