/*
** EPITECH PROJECT, 2024
** int_to_str.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

char *int_to_str(int nbr)
{
    char *str = malloc(sizeof(char) * (int_len(nbr) + 1));
    int i = 0;

    if (nbr == 0)
        return "0";
    if (nbr < 0) {
        str[i] = '-';
        i++;
        nbr = -nbr;
    }
    while (nbr != 0) {
        str[i] = nbr % 10 + '0';
        i++;
        nbr = nbr / 10;
    }
    str[i] = '\0';
    return str_rev(str);
}
