/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Free's a game_obj
*/

#include <stdlib.h>
#include "game_object.h"

sfBool free_comp(component_t *comp)
{
    if (!comp)
        return (sfFalse);
    if (comp->clock)
        sfClock_destroy(comp->clock);
    if (comp->image)
        sfImage_destroy(comp->image);
    if (comp->text)
        sfText_destroy(comp->text);
    if (comp->sound)
        sfSound_destroy(comp->sound);
    return (sfTrue);
}

sfBool free_all_comp(game_obj_t *obj)
{
    register size_t index = 0;

    if (!obj || !(obj->comp))
        return (sfFalse);
    while (obj->comp[index]) {
        free_comp(obj->comp[index]);
        free(obj->comp[index]);
        index += 1;
    }
    free(obj->comp);
    return (sfTrue);
}

sfBool free_obj(game_obj_t *obj)
{
    if (!obj)
        return (sfFalse);
    free_all_comp(obj);
    if (obj->sprite)
        sfSprite_destroy(obj->sprite);
    if (obj->texture)
    sfTexture_destroy(obj->texture);
    return (sfTrue);
}

sfBool free_obj_list(game_obj_t *obj)
{
    game_obj_t *tmp = obj;

    if (!obj)
        return (sfFalse);
    do {
        tmp = obj;
        obj = obj->next;
        if (tmp)
            free_obj(tmp);
    } while (obj);
    return (sfTrue);
}