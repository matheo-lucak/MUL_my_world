/*
** EPITECH PROJECT, 2020
** get hash
** File description:
** get hash from file
*/

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"

int *get_hash(void)
{
    int fd = open("assets/config/hash", O_RDONLY);
    char *stock = get_next_line(fd);
    char **parsed_nb = NULL;
    int *hash = malloc(sizeof(int) * 256);
    int i = 0;

    if (!stock || fd == -1 || !hash)
        return (NULL);
    parsed_nb = my_str_to_word_array(stock, " ,/", 1);
    if (!parsed_nb)
        return (NULL);
    while (parsed_nb[i]) {
        hash[i] = my_getnbr(parsed_nb[i]);
        free(parsed_nb[i]);
        i++;
    }
    free(parsed_nb);
    return (hash);
}