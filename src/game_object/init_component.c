/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_component
*/

#include <stdlib.h>
#include "my.h"
#include "game_object.h"

component_t *add_comp(game_obj_t *obj, prop_t type)
{
    component_t *new_prop = malloc(sizeof(component_t));
    int i = 0;

    while (obj->comp[i] != NULL && i < obj->comp_nb)
        i++;
    if (new_prop == NULL)
        return (NULL);
    new_prop->type = type;
    my_memset((char *)new_prop, '\0', sizeof(component_t));    
    obj->comp[i] = new_prop;
    return (new_prop);
}