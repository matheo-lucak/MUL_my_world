/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** initializes the window
*/

#include "my_world.h"

void init_window_icon(sfRenderWindow *window)
{
    sfImage *image = sfImage_createFromFile("saucisson.png");
    sfUint8 *pixelptr = NULL;
    
    if (image) {
        pixelptr = sfImage_getPixelsPtr(image);
        if (pixelptr) {
            sfRenderWindow_setIcon(window, 200, 121, pixelptr);
        }
        sfImage_destroy(image);
    }
}

win_settings_t init_window(void)
{
    win_settings_t win_sets;

    win_sets.video_mode.width = 1920;
    win_sets.video_mode.height = 1080;
    win_sets.video_mode.bitsPerPixel = 32;
    win_sets.window = sfRenderWindow_create(win_sets.video_mode,
                        "My_world by Matheo Lucak & Guillaume Bogard-Coquard",
                        sfClose | sfDefaultStyle, NULL);
    if (!win_sets.window)
        return (win_sets);
    sfRenderWindow_setFramerateLimit(win_sets.window, 60);
    sfRenderWindow_setMouseCursorVisible(win_sets.window, sfTrue);
    init_window_icon(win_sets.window);
    win_sets.view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    sfView_setCenter(win_sets.view, (sfVector2f){0, 0});
    if (!win_sets.view)
        return (win_sets);
    return (win_sets);
}