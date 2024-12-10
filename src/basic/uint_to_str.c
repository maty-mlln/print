/*
** EPITECH PROJECT, 2024
** uint_to_str.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

char *uint_to_str(unsigned int nb)
{
    char *str = malloc(sizeof(char) * 12);
    int i = 0;

    if (nb == 0)
        return "0";
    while (nb != 0) {
        str[i] = (nb % 10) + '0';
        nb /= 10;
        i++;
    }
    str[i] = '\0';
    return (str_rev(str));
}
