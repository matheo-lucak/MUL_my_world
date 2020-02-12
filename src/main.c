/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** main.c
*/

#include "my.h"
#include "my_world.h"

int main(int ac, char **av, char **env)
{
    if (ac != 1) {
        usage();
        if (ac == 2 && my_strcmp(av[1], "-h", 0))
            return (0);
        return (84);
    }
    my_world();
    return (0);
}