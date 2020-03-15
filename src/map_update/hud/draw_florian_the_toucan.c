/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_florian_the_toucan
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "my_world.h"
#include "game_object.h"
#include "vector_engine.h"

static sfBool does_florian_wants_to_speak(game_obj_t *florian)
{
    sfClock *clock = florian->comp[find_comp(florian, CLOCK)]->clock;

    if (!clock)
        return (sfFalse);
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 2) {
        sfClock_restart(clock);
        return (sfTrue);
    }
    return (sfFalse);
}

static sfBool florian_speak(win_settings_t *sets, game_obj_t *florian,
                                                        char *buffer)
{
    sfText *text = florian->comp[find_comp(florian, TEXT)]->text;
    sfVector2f pos = florian->comp[find_comp(florian, POS)]->v2f;
    sfFloatRect hitbox;

    if (!text)
        return (sfFalse);
    sfText_setScale(text, sets->scale);
    sfText_setColor(text, sfBlack);
    pos.x = florian->pos.x - (florian->view_box.width - pos.x) * sets->scale.x;
    pos.y = florian->pos.y - (florian->view_box.height - pos.y) * sets->scale.y;
    sfText_setPosition(text, pos);
    sfText_setString(text, buffer);
    hitbox = sfText_getGlobalBounds(text);
    if (hitbox.width > 500 * sets->scale.x) {
        sfText_scale(text, vec2f(550 * sets->scale.x / hitbox.width,
                                550 * sets->scale.x / hitbox.width));
    }
    sfRenderWindow_drawText(sets->window, text, NULL);
    return (sfTrue);
}

static sfBool close_florians_beak(int *fd)
{
    if (!fd)
        return (sfFalse);
    while (my_skip_a_file_line(*fd));
    close(*fd);
    *fd = -2;
    return (sfTrue);
}

sfBool florian_the_toucan_wants_to_speak(win_settings_t *sets,
                                            game_obj_t *florian, int do_close)
{
    static int fd = -2;
    static char *buffer = NULL;

    if (fd > 0 && do_close)
        return (close_florians_beak(&fd));
    if (fd == -2)
        fd = open(".legend", O_RDONLY);
    if (does_florian_wants_to_speak(florian)) {
        if (buffer) {
            free(buffer);
            buffer = NULL;
        }
        buffer = get_next_line(fd);
        if (!buffer)
            return (sfFalse);
    }
    return (florian_speak(sets, florian, buffer));
}

void draw_florian_the_toucan(win_settings_t *sets, game_obj_t *florian)
{
    sfVector2f pos;
    float y_offset = 0;

    if (!sets || !florian || !(florian->comp[find_comp(florian, BOOL)]->i))
        return ;
    y_offset = florian->comp[find_comp(florian, OFFSET)]->f;
    pos.x = sets->anchor.topright.x;
    pos.y = sets->anchor.bottomright.y - y_offset * sets->scale.y;
    set_pos(florian, pos.x, pos.y);
    sfSprite_setScale(florian->sprite, sets->scale);
    draw_game_object(*sets, florian);
    if (!florian_the_toucan_wants_to_speak(sets, florian, 0) ||
        (sfFloatRect_contains(&(florian->hitbox),
        sets->mouse_tool.pos.x, sets->mouse_tool.pos.y)
        && sets->mouse_tool.click)) {
        florian->comp[find_comp(florian, BOOL)]->i = 0;
    }
}