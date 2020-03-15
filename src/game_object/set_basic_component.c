/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Sets basic comps of a game_obj.
*/

#include "my.h"
#include "game_object.h"

sfBool set_comp_int(game_obj_t *obj, prop_t type, int nb)
{
    int i = 0;

    if (!obj || !(obj->comp))
        return (sfFalse);
    i = find_comp(obj, type);
    if (!(obj->comp[i]))
        return (sfFalse);
    my_memset((char *)obj->comp[i] + sizeof(prop_t), '\0',
                sizeof(component_t) - sizeof(prop_t));
    obj->comp[i]->i = nb;
    return (sfTrue);
}

sfBool set_comp_float(game_obj_t *obj, prop_t type, float nb)
{
    int i = 0;

    if (!obj || !(obj->comp))
        return (sfFalse);
    i = find_comp(obj, type);
    if (!(obj->comp[i]))
        return (sfFalse);
    my_memset((char *)obj->comp[i] + sizeof(prop_t), '\0',
                sizeof(component_t) - sizeof(prop_t));
    obj->comp[i]->f = nb;
    return (sfTrue);
}

sfBool set_comp_v2i(game_obj_t *obj, prop_t type, sfVector2i vec)
{
    int i = 0;

    if (!obj || !(obj->comp))
        return (sfFalse);
    i = find_comp(obj, type);
    if (!(obj->comp[i]))
        return (sfFalse);
    my_memset((char *)obj->comp[i] + sizeof(prop_t), '\0',
            sizeof(component_t) - sizeof(prop_t));
    obj->comp[i]->v2i = vec;
    return (sfTrue);
}

sfBool set_comp_v2f(game_obj_t *obj, prop_t type, sfVector2f vec)
{
    int i = 0;

    if (!obj || !(obj->comp))
        return (sfFalse);
    i = find_comp(obj, type);
    if (!(obj->comp[i]))
        return (sfFalse);
    my_memset((char *)obj->comp[i] + sizeof(prop_t), '\0',
            sizeof(component_t) - sizeof(prop_t));
    obj->comp[i]->v2f = vec;
    return (sfTrue);
}

sfBool set_comp_irect(game_obj_t *obj, prop_t type, sfIntRect rect)
{
    int i = 0;

    if (!obj || !(obj->comp))
        return (sfFalse);
    i = find_comp(obj, type);
    if (!(obj->comp[i]))
        return (sfFalse);
    my_memset((char *)obj->comp[i] + sizeof(prop_t), '\0',
            sizeof(component_t) - sizeof(prop_t));
    obj->comp[i]->irect = rect;
    return (sfTrue);
}