/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Draws the current amount of frames per second onto the upper right corner
*/

#include <stdlib.h>
#include "my.h"
#include "my_world.h"
#include "vector_engine.h"

static void reset_fps_string(sfText *fps_drawer, char fps_string[20],
                                sfBool *first_call)
{
    my_strcpy(fps_string, "FPS: 0");
    fps_string[19] = '\0';
    sfText_setString(fps_drawer, fps_string);
    *first_call = sfFalse;
}

static void update_fps(fps_assets_t *fps_assets, char fps_string[20])
{
    char *tmp = NULL;

    tmp = my_int_to_str(fps_assets->fps_counter);
    if (!tmp)
        return;
    my_strcpy(fps_string + 5, tmp);
    if (tmp)
        free(tmp);
    fps_assets->fps_counter = 0;
    sfText_setString(fps_assets->fps_drawer, fps_string);
}

static void draw_fps_onto_window(win_settings_t sets,
                                fps_assets_t *fps_assets)
{
    sfVector2f offset = vec2f(sets.scale.x *
                        -(sfText_getLocalBounds(fps_assets->fps_drawer).width),
                        0);

    sfText_setPosition(fps_assets->fps_drawer, sets.anchor.topright);
    sfText_move(fps_assets->fps_drawer, offset);
    sfText_setScale(fps_assets->fps_drawer, sets.scale);
    sfRenderWindow_drawText(sets.window, fps_assets->fps_drawer, NULL);
}

void draw_fps(win_settings_t sets, fps_assets_t *fps_assets)
{
    static char fps_string[20];
    static sfBool first_call = sfTrue;

    if (first_call)
        reset_fps_string(fps_assets->fps_drawer, fps_string, &first_call);
    if (!fps_assets || !(fps_assets->clock))
        return;
    fps_assets->fps_counter += 1;
    if (sfTime_asSeconds(sfClock_getElapsedTime(fps_assets->clock)) > 1) {
        update_fps(fps_assets, fps_string);
        sfClock_restart(fps_assets->clock);
    }
    draw_fps_onto_window(sets, fps_assets);
}