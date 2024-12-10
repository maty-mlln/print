/*
** EPITECH PROJECT, 2024
** str_dup.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

char *str_dup(char const *src)
{
    char *dest = malloc(sizeof(char) * (str_len(src) + 1));
    int i = 0;

    if (!dest)
        return NULL;
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
