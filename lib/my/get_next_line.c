/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** gets the next line of a file
*/

#include <stdlib.h>
#include <unistd.h>

static char *my_strdup(char *template, const char end,
                        const unsigned int free_template)
{
    char *dup = NULL;
    int len_template = -1;
    int i = -1;

    if (!template)
        return (NULL);
    while (template[++len_template] != end && template[len_template]);
    dup = malloc(sizeof(char) * (len_template + 1));
    if (!dup)
        return (NULL);
    while (++i < len_template)
        dup[i] = template[i];
    dup[i] = '\0';
    if (template && free_template)
        free(template);
    return (dup);
}

static char *my_strcat(char *first, char *second)
{
    char *result = NULL;
    int count_tmp = -1;
    int count_res = -1;

    if (!first || !second)
        return (!first) ? my_strdup(second, 0, 0) : my_strdup(first, 0, 0);
    while (first[++count_tmp]);
    while (second[++count_res]);
    result = malloc(sizeof(char) * (count_tmp + count_res + 1));
    if (!result)
        return (NULL);
    count_res = 0;
    for (count_tmp = 0; first[count_tmp]; count_tmp += 1)
        result[count_res++] = first[count_tmp];
    for (count_tmp = 0; second[count_tmp]; count_tmp += 1)
        result[count_res++] = second[count_tmp];
    result[count_res] = '\0';
    if (first)
        free(first);
    return (result);
}

static char *get_line(const int fd, char **res, int *i, const int nb_bytes)
{
    static char *tmp = NULL;
    static int size = 0;

    do {
        tmp = malloc(sizeof(char) * (nb_bytes + 1));
        if (!tmp)
            return (NULL);
        size = read(fd, tmp, nb_bytes);
        if (size <= 0)
            return (my_strdup(*res, '\n', 0));
        tmp[size] = '\0';
        *res = my_strcat(*res, tmp);
        if (tmp && tmp != *res)
            free(tmp);
        if (!(*res))
            return (NULL);
        while ((*res)[*i] && (*res)[*i] != '\n')
            (*i) += 1;
    } while (*res && (*res)[*i] != '\n');
    return (my_strdup(*res, '\n', 0));
}

static int did_stock_save_line(char **stock, char *res, char **line)
{
    int index = 0;

    if ((*stock) && !((*stock)[0])) {
        free(*stock);
        *stock = NULL;
    }
    if (!(*stock))
        return (0);
    res = my_strdup(*stock, '\0', 0);
    if (!res)
        return (1);
    while ((*stock)[index] && (*stock)[index] != '\n')
        index += 1;
    if ((*stock)[index] == '\n') {
        *stock = my_strdup(&res[index + 1], '\0', 0);
        *line = my_strdup(res, '\n', 1);
        return (1);
    }
    free(res);
    return (0);
}

char *get_next_line(const int fd, const int nb_bytes)
{
    static char *stock = NULL;
    char *line = NULL;
    char *res = NULL;
    int index = 0;

    if (fd == -1 || nb_bytes <= 0)
        return (NULL);
    if (did_stock_save_line(&stock, res, &line))
        return (line);
    if (stock)
        res = my_strdup(stock, '\0', 1);
    line = get_line(fd, &res, &index, nb_bytes);
    if (res) {
        stock = my_strdup(&res[index + 1], '\0', 0);
        free(res);
    }
    return (line);
}