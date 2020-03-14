/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** hovering_earth_action.c
*/

#include "my_world.h"

sfBool hovering_earth_action(const game_obj_t *earth,
                            const mouse_tool_t mouse)
{
    static sfBool hovering = sfFalse;
    const sfColor full_opacity = (sfColor){255, 255, 255, 255};
    const sfColor darker = (sfColor){255, 255, 255, 100};

    if (!hovering && sfFloatRect_contains(&earth->hitbox,
                                        mouse.pos.x, mouse.pos.y)) {
        hovering = sfTrue;
        sfSprite_setColor(earth->sprite, darker);
    }
    if (hovering && !sfFloatRect_contains(&earth->hitbox,
                                        mouse.pos.x, mouse.pos.y)) {
        hovering = sfFalse;
        sfSprite_setColor(earth->sprite, full_opacity);
    }
    if (hovering && sfMouse_isButtonPressed(sfMouseLeft))
        return (sfTrue);
    return (sfFalse);
}