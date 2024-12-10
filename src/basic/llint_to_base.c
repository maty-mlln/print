/*
** EPITECH PROJECT, 2024
** llint_to_base.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

static char *llint_to_base_rec(long long int nbr, char const *base, int len)
{
    char *result = malloc(sizeof(char) * 100);
    int i = 0;

    if (nbr >= len) {
        for (int j = 0; j < str_len(llint_to_base_rec(nbr / len, base, len));
            j++) {
            result[i] = llint_to_base_rec(nbr / len, base, len)[j];
            i++;
        }
        result[i] = base[nbr % len];
        i++;
    } else {
        result[i] = base[nbr];
        i++;
    }
    result[i] = '\0';
    return result;
}

char *llint_to_base(long long int nbr, char const *base)
{
    int len = str_len(base);
    char *result = malloc(sizeof(char) * 100);
    int i = 0;
    char *temp;

    if (nbr < 0) {
        result[i] = '-';
        i++;
        nbr = -nbr;
    }
    temp = llint_to_base_rec(nbr, base, len);
    for (int j = 0; j < str_len(temp); j++) {
        result[i] = temp[j];
        i++;
    }
    result[i] = '\0';
    free(temp);
    return result;
}
