/*
** EPITECH PROJECT, 2019
** library
** File description:
** gets the size of an integer
*/

int my_int_size(int nb)
{
    int i = 1;

    if (nb < 0)
        nb *= -1;
    if (nb == 0)
        return (1);
    while (nb >= 9) {
        nb /= 10;
        i += 1;
    }
    return (i);
}