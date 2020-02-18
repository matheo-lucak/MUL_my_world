/*
** EPITECH PROJECT, 2020
** get hash
** File description:
** get hash from file
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

static void free_hash_resources(const int fd, int *hash)
{
    if (fd != -1)
        close(fd);
    if (hash)
        free(hash);
}

static char **get_parsed_nbrs(const int fd, int *hash)
{
    char **parsed_nbrs = NULL;
    char *stock = NULL;

    if (fd == -1 || !hash) {
        free_hash_resources(fd, hash);
        return (NULL);
    }
    stock = get_next_line(fd);
    if (!stock) {
        free_hash_resources(fd, hash);
        return (NULL);
    }
    parsed_nbrs = my_str_to_word_array(stock, ", /", 1);
    if (!parsed_nbrs) {
        free_hash_resources(fd, hash);
        return (NULL);
    }
    return (parsed_nbrs);
}

int *get_hash(void)
{
    char **parsed_nbrs = NULL;
    int *hash = malloc(sizeof(int) * 256);
    int index = 0;
    int fd = open("assets/config/hash", O_RDONLY);

    parsed_nbrs = get_parsed_nbrs(fd, hash);
    if (!parsed_nbrs)
        return (NULL);
    while (parsed_nbrs[index]) {
        hash[index] = my_getnbr(parsed_nbrs[index]);
        if (parsed_nbrs[index])
            free(parsed_nbrs[index]);
        index += 1;
    }
    free(parsed_nbrs);
    close(fd);
    return (hash);
}