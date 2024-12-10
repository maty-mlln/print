/*
** EPITECH PROJECT, 2024
** int_to_str.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

char *int_to_str(int nb)
{
    char *str = malloc(sizeof(char) * (int_len(nb) + 1));
    int i = 0;

    if (nb == 0)
        return "0";
    if (nb < 0) {
        str[i] = '-';
        i++;
        nb = -nb;
    }
    while (nb != 0) {
        str[i] = nb % 10 + '0';
        i++;
        nb = nb / 10;
    }
    str[i] = '\0';
    return (str_rev(str));
}
