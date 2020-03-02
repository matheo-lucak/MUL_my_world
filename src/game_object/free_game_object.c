/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** free_game_object
*/

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
    int i = 0;

    if (!obj || !(obj->comp))
        return (sfFalse);
    while (obj->comp[i]) {
        free_comp(obj->comp[i]);
        free(obj->comp[i]);
        i++;
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