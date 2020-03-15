/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_text_box
*/

#include "my_world.h"
#include "game_object.h"
#include "vector_engine.h"


void check_alph(char text[50], int *text_index)
{
    static const char alph_num[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    int letter = 0;

    while (letter < 36) {
        if (sfKeyboard_isKeyPressed((sfKeyCode)letter) && *text_index < 48) {
            text[*text_index] = alph_num[letter];
            *text_index += 1;
            while (sfKeyboard_isKeyPressed((sfKeyCode)letter));
        }
        letter += 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyBack) && *text_index > 0) {
        text_index[*text_index] = '\0';
        *text_index = *text_index - 1;
        text_index[*text_index] = '\0';
        while (sfKeyboard_isKeyPressed(sfKeyBack));
    }
}

static void draw_drawer_text(win_settings_t *sets, game_obj_t *text_box)
{
    static int text_index = 0;
    static char text[50];
    sfText *text_drawer = text_box->comp[find_comp(text_box, TEXT)]->text;
    sfFloatRect hitbox;

    text[49] = 0;
    if (!text_drawer)
        return ;
    hitbox = sfText_getLocalBounds(text_drawer);
    sfText_setOrigin(text_drawer, vec2f(hitbox.width / 2, hitbox.height / 2));
    sfText_setPosition(text_drawer, text_box->pos);
    check_alph(text, &text_index);
    sfText_setString(text_drawer, text);
    sfRenderWindow_drawText(sets->window, text_drawer, NULL);
}

static void draw_active_text_box(win_settings_t *sets, map_formatter_t *ter,
                    game_obj_t *text_box, game_obj_t *save_button)
{
    sfVector2f center = {0, 0};
    float x_scale = 0;

    if (!(text_box->view_box.width))
        return ;
    center.x = (sets->anchor.topleft.x + sets->anchor.topright.x) / 2;
    center.y = (sets->anchor.topleft.y + sets->anchor.bottomleft.y) / 2;
    x_scale = sets->size.x / (text_box->view_box.width * 2);
    set_pos(text_box, center.x, center.y);
    sfSprite_setScale(text_box->sprite, sets->scale);
    sfSprite_scale(text_box->sprite, vec2f(x_scale, x_scale));
    draw_game_object(*sets, text_box);
    draw_drawer_text(sets, text_box);
}

void draw_text_box(win_settings_t *sets, map_formatter_t *ter,
                    game_obj_t *save_button, game_obj_t *text_box)
{
    game_obj_t *load_button = find_game_object(save_button, LOAD_BUTTON);

    if (!sets || !ter || !save_button || !load_button)
        return ;
    if (save_button->comp[find_comp(save_button, BOOL)]->i ||
        load_button->comp[find_comp(load_button, BOOL)]->i)
        draw_active_text_box(sets, ter, text_box, save_button);
}