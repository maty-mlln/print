/*
** EPITECH PROJECT, 2024
** str_cpy.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

char *str_cpy(char *dest, char *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
