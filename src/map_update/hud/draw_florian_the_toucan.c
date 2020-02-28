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
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 1) {
        sfClock_restart(clock);
        return (sfTrue);
    }
    return (sfFalse);
}

static void florian_speak(win_settings_t *sets, game_obj_t *florian, char *buffer)
{
    sfText *text = florian->comp[find_comp(florian, TEXT)]->text;
    sfVector2f pos = florian->comp[find_comp(florian, POS)]->v2f;

    if (!text)
        return ;
    sfText_setScale(text, sets->scale);
    sfText_setColor(text, sfBlack);
    pos.x = florian->pos.x - (florian->view_box.width - pos.x) * sets->scale.x;
    pos.y = florian->pos.y - (florian->view_box.height - pos.y) * sets->scale.y;
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(sets->window, text, NULL);
    sfText_setString(text, buffer);
}

static sfBool florian_the_toucan_wants_to_speak(win_settings_t *sets,
                                            game_obj_t *florian, int do_close)
{
    static int fd = -2;
    static char *buffer = NULL;

    if (fd == -2)
        fd = open(".legend", O_RDONLY);
    if (does_florian_wants_to_speak(florian)) {
        if (buffer) {
            free(buffer);
            buffer = NULL;
        }
        buffer = get_next_line(fd);
    }
    florian_speak(sets, florian, buffer);
    if (fd > 0 && do_close)
        close(fd);
    return (sfTrue);
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
        && sets->mouse_tool.click))
        florian->comp[find_comp(florian, BOOL)]->i = 0;
}