/*
** EPITECH PROJECT, 2024
** uint_to_base.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

char *uint_to_base(unsigned int nbr, char const *base)
{
    int base_len = str_len(base);
    char *result = malloc(sizeof(char) * 100);
    int i = 0;

    while (nbr != 0) {
        result[i] = base[nbr % base_len];
        nbr /= base_len;
        i++;
    }
    result[i] = '\0';
    return rev_str(result);
}
