/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** converts a string into an array from its words
*/

#include <stdlib.h>
#include "my.h"

static int get_nb_words(const char *sentence, const char splitters[])
{
    int nb_words = 0;
    int idx = 0;

    while (sentence[idx] && find_char_in_str(splitters, sentence[idx]))
        idx += 1;
    while (sentence[idx]) {
        while (sentence[idx] && !find_char_in_str(splitters, sentence[idx]))
            idx += 1;
        while (sentence[idx] && find_char_in_str(splitters, sentence[idx]))
            idx += 1;
        nb_words += 1;
    }
    return (nb_words);
}

static char **fill_result(char *sentence, const char splitters[],
                            char **res, const unsigned int freer)
{
    int idx = 0;
    int idx_res = 0;

    while (sentence[idx] && find_char_in_str(splitters, sentence[idx]))
        idx += 1;
    while (sentence[idx]) {
        res[idx_res] = my_strdup_cmpstr(&sentence[idx], splitters);
        while (sentence[idx] && !find_char_in_str(splitters, sentence[idx]))
            idx += 1;
        while (sentence[idx] && find_char_in_str(splitters, sentence[idx]))
            idx += 1;
        idx_res += 1;
    }
    if (sentence && freer)
        free(sentence);
    return (res);
}

char **my_str_to_word_array(char *sentence, const char splitters[],
                            const unsigned int freer)
{
    char **res = NULL;
    int nb_words = 0;

    if (!sentence)
        return (NULL);
    nb_words = get_nb_words(sentence, splitters);
    if (nb_words == 0)
        return (NULL);
    res = malloc(sizeof(char *) * (nb_words + 1));
    if (!res)
        return (NULL);
    res[nb_words] = NULL;
    return (fill_result(sentence, splitters, res, freer));
}