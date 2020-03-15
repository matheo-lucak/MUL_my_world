/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_text_box
*/


#include "my.h"
#include "my_world.h"
#include "game_object.h"
#include "vector_engine.h"


static void check_alph(char text[21], int *text_index)
{
    static const char alph_num[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    int letter = 0;

    while (letter < 36) {
        if (sfKeyboard_isKeyPressed((sfKeyCode)letter) && *text_index < 20) {
            text[*text_index] = alph_num[letter];
            *text_index += 1;
            while (sfKeyboard_isKeyPressed((sfKeyCode)letter));
        }
        letter += 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyBack) && *text_index > 0) {
        *text_index = *text_index - 1;
        text[*text_index] = '\0';
        while (sfKeyboard_isKeyPressed(sfKeyBack));
    }
}

static void draw_drawer_text(win_settings_t *sets, char text[21],
                                int *text_index, game_obj_t *text_box)
{
    sfText *text_drawer = text_box->comp[find_comp(text_box, TEXT)]->text;
    sfFloatRect hitbox;

    if (!text_drawer)
        return ;
    hitbox = sfText_getLocalBounds(text_drawer);
    sfText_setOrigin(text_drawer, vec2f(hitbox.width / 2, hitbox.height / 2));
    sfText_setPosition(text_drawer, text_box->pos);
    sfText_setScale(text_drawer, sets->scale);
    check_alph(text, text_index);
    sfText_setString(text_drawer, text);
    sfRenderWindow_drawText(sets->window, text_drawer, NULL);
}

static sfBool load_or_save_map(map_formatter_t *ter, char text[21],
                                int *text_index, sfVector2i boolean)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter) && (boolean.x || boolean.y)) {
        while (sfKeyboard_isKeyPressed(sfKeyEnter));
        if (boolean.x) {
            save_map(*ter, text);
        } else if (boolean.y) {
            open_map(ter, text);
        }
        my_memset(text, 0, 21);
        *text_index = 0;
        return (sfTrue);
    }
    return (sfFalse);
}

static sfBool draw_active_text_box(win_settings_t *sets, map_formatter_t *ter,
                    game_obj_t *text_box, sfVector2i boolean)
{
    static char text[21];
    static int text_index = 0;
    sfVector2f center = {0, 0};
    float x_scale = 0;

    if (!(text_box->view_box.width))
        return (sfFalse);
    center.x = (sets->anchor.topleft.x + sets->anchor.topright.x) / 2;
    center.y = (sets->anchor.topleft.y + sets->anchor.bottomleft.y) / 2;
    x_scale = sets->size.x / (text_box->view_box.width * 2);
    set_pos(text_box, center.x, center.y);
    sfSprite_setScale(text_box->sprite, sets->scale);
    sfSprite_scale(text_box->sprite, vec2f(x_scale, x_scale));
    draw_game_object(*sets, text_box);
    draw_drawer_text(sets, text, &text_index, text_box);
    return (load_or_save_map(ter, text, &text_index, boolean));
}

void draw_text_box(win_settings_t *sets, map_formatter_t *ter,
                    game_obj_t *save_button, game_obj_t *text_box)
{
    game_obj_t *load_button = find_game_object(save_button, LOAD_BUTTON);
    sfVector2i boolean = {0, 0};

    if (!sets || !ter || !save_button || !load_button)
        return ;
    boolean.x = save_button->comp[find_comp(save_button, BOOL)]->i;
    boolean.y = load_button->comp[find_comp(load_button, BOOL)]->i;
    if (boolean.x || boolean.y) {
        sets->paused = sfTrue;
        if (draw_active_text_box(sets, ter, text_box, boolean)) {
            sets->paused = sfFalse;
            boolean.x = save_button->comp[find_comp(save_button, BOOL)]->i = 0;
            boolean.y = load_button->comp[find_comp(load_button, BOOL)]->i = 0;
        }
    }
}