/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Updates the pixel list
*/

#include "my_world.h"
#include "pixel.h"
#include "vector_engine.h"

static void is_new_pixel(const mouse_tool_t mouse, pixellist_t **head)
{
    if (sfMouse_isButtonPressed(sfMouseRight)) {
        pixellist_add_x_pixels(head,
                            (sfFloatRect){mouse.pos.x - 1, mouse.pos.y - 1,
                            mouse.pos.x, mouse.pos.y},
                            1);
    }
}

void update_pixellist(win_settings_t sets, pixellist_t **head,
                        sfRectangleShape *rect)
{
    pixellist_t *tmp = NULL;

    if (!rect || !head)
        return;
    is_new_pixel(sets.mouse_tool, head);
    if (!(*head))
        return;
    tmp = (*head);
    do {
        update_pixel_physic(sets, tmp);
        sfRectangleShape_setPosition(rect, tmp->pos);
        update_pixel_color(sets, tmp, rect);
        sfRenderWindow_drawRectangleShape(sets.window, rect, NULL);
        tmp = tmp->next;
    } while (tmp != *head && tmp);
}