/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Inits a comp.
*/

#include <stdlib.h>
#include "my.h"
#include "init_comp_game_object.h"
#include "game_object.h"

static sfBool (*init_component[])(game_obj_t *obj, char *buffer);

static char *component_pattern[];

int find_init_component(char *buffer)
{
    int index = 0;

    if (!buffer)
        return (-1);
    while (component_pattern[index]) {
        if (my_hay_needle(buffer, component_pattern[index]) != -1)
            return (index);
        index += 1;
    }
    return (-1);
}

sfBool set_component(game_obj_t *obj, char *buffer)
{
    int index = 0;

    if (!buffer)
        return (sfFalse);
    add_comp(obj, (prop_t)my_getnbr(buffer));
    while (component_pattern[index]) {
        if (my_hay_needle(buffer, component_pattern[index]) != -1)
            return (init_component[index](obj, buffer));
        index += 1;
    }
    return (sfFalse);
}

sfBool set_all_component(game_obj_t *obj, int fd, char *buffer)
{
    int index = 0;

    if (!buffer || my_hay_needle(buffer, "component : ") == -1) {
        obj->comp = NULL;
        return (sfFalse);
    }
    obj->comp_nb = my_getnbr((buffer + my_strlen("component : ")));
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    if (!(obj->comp))
        return  (sfFalse);
    for (index = 0; index < obj->comp_nb + 1; index += 1)
        obj->comp[index] = NULL;
    do {
        buffer = get_next_line(fd);
        if (buffer && !set_component(obj, buffer))
            return (sfFalse);
    } while (buffer);
    return (sfTrue);
}

component_t *add_comp(game_obj_t *obj, prop_t type)
{
    component_t *new_prop = malloc(sizeof(component_t));
    int index = 0;

    while (obj->comp[index] && index < obj->comp_nb)
        index += 1;
    if (!new_prop)
        return (NULL);
    my_memset((char *)new_prop, '\0', sizeof(component_t));
    new_prop->type = type;
    obj->comp[index] = new_prop;
    return (new_prop);
}