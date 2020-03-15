/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** open_map
*/

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "my_world.h"
#include "map_generation.h"
#include "map_update.h"

static sfBool set_map_size(int fd, sfVector2i *map_size, int *seed)
{
    char **parsed_line = NULL;
    int arr_len = 0;

    if (!map_size)
        return (sfFalse);
    parsed_line = my_str_to_word_array(get_next_line(fd), " ;", 1);
    if (!parsed_line)
        return (sfFalse);
    arr_len = my_arrlen((void **)parsed_line);
    if (arr_len < 2 || arr_len > 3)
        return (sfFalse);
    map_size->x = my_getnbr(parsed_line[0]);
    map_size->y = my_getnbr(parsed_line[1]);
    if (arr_len == 3 && seed)
        *seed = my_getnbr(parsed_line[2]);
    my_free_arr(parsed_line);
    if (map_size->x <= 0 || map_size->y <= 0)
        return (sfFalse);
    return (sfTrue);
}

static float *fill_float_array(int fd, int map_width)
{
    char **parsed_line = NULL;
    float *new_line = NULL;
    int x = 0;

    parsed_line = my_str_to_word_array(get_next_line(fd), " ;", 1);
    new_line = malloc(sizeof(float) * map_width);
    if (!parsed_line || !new_line)
        return (NULL);
    if (my_arrlen((void **)parsed_line) != map_width)
        return (NULL);
    while (x < map_width) {
        if (!(parsed_line[x]))
            return (NULL);
        new_line[x] = (float)my_getnbr(parsed_line[x]) / 100;
        x += 1;
    }
    my_free_arr(parsed_line);
    return (new_line);
}

float **get_3d_map_from_file(int fd, sfVector2i *size)
{
    float **map_3d = NULL;
    int y = 0;
    int seed = 0;

    if (!set_map_size(fd, size, &seed))
        return (NULL);
    if (seed > 0) {
        return (generate_map(*size, seed));
    }
    map_3d = malloc(sizeof(float *) * size->y);
    if (!map_3d)
        return (NULL);
    while (y < size->y) {
        map_3d[y] = fill_float_array(fd, size->x);
        if (!(map_3d[y]))
            return (NULL);
        y += 1;
    }
    return (map_3d);
}

static sfBool init_n_apply_new_maps(int fd, map_formatter_t *ter)
{
    sfVector2i size = {0, 0};
    float **map_3d = get_3d_map_from_file(fd, &size);
    sfVector2f **map_2d = init_map_2d(size);
    tile_t **tile_map_2d = init_tile_map_2d(size, ter->textures, ter->shaders);

    if (!map_3d || !map_2d || !tile_map_2d) {
        my_printf("Couldn't open map !\n");
        return (sfFalse);
    }
    free_array((void **)ter->map_3d, ter->map_settings.size.y);
    free_array((void **)ter->map_2d, ter->map_settings.size.y);
    free_array((void **)ter->tile_map_2d, ter->map_settings.size.y - 1);
    ter->map_settings.size = size;
    ter->map_3d = map_3d;
    ter->map_2d = map_2d;
    ter->tile_map_2d = tile_map_2d;
    return (sfTrue);
}

sfBool open_map(map_formatter_t *ter, char *file_name)
{
    int fd = 0;

    if (!file_name || !ter)
        return (sfFalse);
    fd = open(file_name, O_RDONLY);
    if (!init_n_apply_new_maps(fd, ter))
        return (sfFalse);
    apply_biomes(ter);
    update_map_2d(ter);
    update_tile_map_2d(ter);
    return (sfTrue);
}