/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_texture_mode_button
*/

#include "texture_mode_button.h"
#include "vector_engine.h"

static void link_texture_bar_function(win_settings_t *sets,
                                        game_obj_t *texture_b,
                                        texture_matter_t tex_matter)
{
    sfFloatRect hitbox = {0, 0, 0, 0};
    sfBool overlap = 0;
    sfSound *sound = NULL;

    if (!sets || !texture_b)
        return ;
    hitbox = sfSprite_getGlobalBounds(texture_b->sprite);
    overlap = sfFloatRect_contains(&hitbox, sets->mouse_tool.pos.x,
                                                    sets->mouse_tool.pos.y);
    if (overlap && sets->mouse_tool.click) {
        sound = texture_b->comp[find_comp(texture_b, SOUND)]->sound;
        if (sound)
            sfSound_play(sound);
        sets->mode.matter = tex_matter.matter;
    }
}

static void draw_texture_frame(win_settings_t *sets, game_obj_t *texture_b,
                                                texture_matter_t tex_matter)
{
    static sfSprite *sprite = NULL;
    sfFloatRect bounds;
    sfVector2f sprite_scale;

    if (!sprite)
        sprite = sfSprite_create();
    sfSprite_setTexture(sprite, tex_matter.texture, sfFalse);
    bounds = sfSprite_getLocalBounds(sprite);
    if (!(bounds.width) || !(bounds.height))
        return ;
    sprite_scale.x = texture_b->view_box.width / bounds.width;
    sprite_scale.y = texture_b->view_box.height / bounds.height;
    sfSprite_setPosition(sprite, texture_b->pos);
    sfSprite_setScale(sprite, sets->scale);
    sfSprite_scale(sprite, sprite_scale);
    sfRenderWindow_drawSprite(sets->window, sprite, NULL);
}

static void draw_texture_bar_tile(win_settings_t *sets, game_obj_t *slider,
                                texture_matter_t tex_matter, float x_offset)
{
    game_obj_t *texture_b = find_game_object(slider, TEXTURE_BAR);
    sfVector2i tpos;
    sfVector2f pos;

    if (!texture_b || !sets || !(slider->view_box.height))
        return ;
    texture_b->view_box.left = tex_matter.matter != sets->mode.matter ?
                                        texture_b->view_box.width : 0;
    tpos = texture_b->comp[find_comp(texture_b, POS)]->v2i;
    tpos.x += x_offset;
    tpos.y += (texture_b->view_box.height + 30) * tex_matter.matter;
    tpos.y *= sets->size.y / slider->view_box.height;
    pos = sfRenderWindow_mapPixelToCoords(sets->window,
                                            tpos, sets->view);
    set_pos(texture_b, pos.x, pos.y);
    sfSprite_setScale(texture_b->sprite, sets->scale);
    draw_texture_frame(sets, texture_b, tex_matter);
    draw_game_object(*sets, texture_b);
    link_texture_bar_function(sets, texture_b, tex_matter);
}

void draw_texture_bar(win_settings_t *sets, map_formatter_t ter,
                                game_obj_t *slider, float x_offset)
{
    int index = 0;
    texture_matter_t tex_matter = {NULL, 0};

    if (!sets || !slider || !(ter.textures)
        || sets->mode.edit_mode != TEXTURE_MODE)
        return ;
    while (ter.textures[index]) {
        tex_matter.texture = ter.textures[index];
        tex_matter.matter = (tile_matter_t)index;
        draw_texture_bar_tile(sets, slider, tex_matter, x_offset);
        index += 1;
    }
}