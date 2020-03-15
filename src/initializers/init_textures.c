/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Initializes textures.
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "my_world.h"

static int get_first_nb(const int fd)
{
    char *first_line = get_next_line(fd);
    int nb = 0;

    nb = my_getnbr(first_line);
    if (first_line)
        free(first_line);
    return (nb);
}

static sfBool check_textures_error(const int fd,
                                        const int nb_textures,
                                        sfTexture ***textures)
{
    if (fd == -1 || nb_textures <= 0)
        return (sfFalse);
    *textures = malloc(sizeof(sfTexture *) * (nb_textures + 1));
    if (!(*textures))
        return (sfFalse);
    return (sfTrue);
}

sfTexture **init_textures(void)
{
    sfTexture **textures = NULL;
    char *line = NULL;
    int fd = open("assets/config/texture", O_RDONLY);
    int nb_textures = get_first_nb(fd);
    int index = 0;

    if (!check_textures_error(fd, nb_textures, &textures))
        return (NULL);
    while (index < nb_textures) {
        line = get_next_line(fd);
        textures[index] = sfTexture_createFromFile(line, NULL);
        if (line)
            free(line);
        index += 1;
    }
    textures[index] = NULL;
    close(fd);
    return (textures);
}