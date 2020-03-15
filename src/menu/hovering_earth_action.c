/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Handles the hovering actions between the mouse and the earth.
*/

#include "my_world.h"

sfBool hovering_earth_action(const game_obj_t *earth,
                            const mouse_tool_t mouse)
{
    static sfBool hovering = sfFalse;

    if (!hovering
        && sfFloatRect_contains(&earth->hitbox, mouse.pos.x, mouse.pos.y)) {
        hovering = sfTrue;
        sfSprite_setColor(earth->sprite, darker);
    }
    if (hovering
        && !sfFloatRect_contains(&earth->hitbox, mouse.pos.x, mouse.pos.y)) {
        hovering = sfFalse;
        sfSprite_setColor(earth->sprite, full_opacity);
    }
    if (hovering && mouse.click)
        return (sfTrue);
    return (sfFalse);
}