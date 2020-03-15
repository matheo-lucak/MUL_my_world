/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Sets advanced comps of a game_obj.
*/

#include "my.h"
#include "game_object.h"

sfBool set_comp_clock(game_obj_t *obj, prop_t type)
{
    int i = 0;

    if (!obj || !(obj->comp))
        return (sfFalse);
    i = find_comp(obj, type);
    if (!(obj->comp[i]))
        return (sfFalse);
    my_memset((char *)obj->comp[i] + sizeof(prop_t), '\0',
                sizeof(component_t) - sizeof(prop_t));
    obj->comp[i]->clock = sfClock_create();
    if (!(obj->comp[i]->clock))
        return (sfFalse);
    return (sfTrue);
}

sfBool reset_comp_clock(game_obj_t *obj, prop_t type)
{
    int i = 0;

    if (!obj || !(obj->comp))
        return (sfFalse);
    i = find_comp(obj, type);
    if (!(obj->comp[i]))
        return (sfFalse);
    my_memset((char *)obj->comp[i] + sizeof(prop_t), '\0',
            sizeof(component_t) - sizeof(prop_t));
    if (!(obj->comp[i]->clock))
        return (sfFalse);
    sfClock_restart(obj->comp[i]->clock);
    return (sfTrue);
}

sfBool set_comp_image(game_obj_t *obj, prop_t type, char *path)
{
    int i = 0;

    if (!obj || !(obj->comp))
        return (sfFalse);
    i = find_comp(obj, type);
    if (!(obj->comp[i]))
        return (sfFalse);
    my_memset((char *)obj->comp[i] + sizeof(prop_t), '\0',
                sizeof(component_t) - sizeof(prop_t));
    obj->comp[i]->image = sfImage_createFromFile(path);
    if (!(obj->comp[i]->image))
        return (sfFalse);
    return (sfTrue);
}

sfBool set_comp_text(game_obj_t *obj, prop_t type, char *path, int size)
{
    int i = 0;
    sfFont *font = sfFont_createFromFile(path);

    if (!obj || !(obj->comp))
        return (sfFalse);
    i = find_comp(obj, type);
    if (!(obj->comp[i]))
        return (sfFalse);
    my_memset((char *)obj->comp[i] + sizeof(prop_t), '\0',
                sizeof(component_t) - sizeof(prop_t));
    obj->comp[i]->text = sfText_create();
    if (!font || !(obj->comp[i]->text))
        return (sfFalse);
    sfText_setFont(obj->comp[i]->text, font);
    sfText_setCharacterSize(obj->comp[i]->text, size);
    return (sfTrue);
}

sfBool set_comp_sound(game_obj_t *obj, prop_t type, char *path, float volume)
{
    int i = find_comp(obj, type);
    sfSoundBuffer *sound_buffer = sfSoundBuffer_createFromFile(path);

    if (!obj || !(obj->comp))
        return (sfFalse);
    i = find_comp(obj, type);
    if (!(obj->comp[i]))
        return (sfFalse);
    my_memset((char *)obj->comp[i] + sizeof(prop_t), '\0',
                sizeof(component_t) - sizeof(prop_t));
    obj->comp[i]->sound = sfSound_create();
    if (!sound_buffer || !(obj->comp[i]->sound))
        return (sfFalse);
    sfSound_setBuffer(obj->comp[i]->sound, sound_buffer);
    sfSound_setVolume(obj->comp[i]->sound, volume);
    return (sfTrue);
}