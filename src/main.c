/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** Main function of my_world.
*/

#include "my.h"
#include "my_world.h"

static sfBool check_env(const char * const env[])
{
    const char display[] = "DISPLAY";
    int index = 0;

    if (!env || !env[0])
        return (sfFalse);
    while (env[index]) {
        if (!my_strncmp(env[index], display, my_strlen(display)))
            return (sfTrue);
        index += 1;
    }
    return (sfFalse);
}

int main(const int ac, const char * const av[], const char * const env[])
{
    if (!check_env(env))
        return (84);
    if (ac != 1) {
        usage();
        if (ac == 2 && !my_strcmp(av[1], "-h", 0))
            return (0);
        return (84);
    }
    window_actions();
    return (0);
}