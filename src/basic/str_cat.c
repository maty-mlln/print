/*
** EPITECH PROJECT, 2024
** str_cat.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

char *str_cat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char *new_str = malloc(sizeof(char) * (str_len(dest) + str_len(src) + 1));

    if (new_str == NULL)
        return NULL;
    while (dest[i] != '\0') {
        new_str[i] = dest[i];
        i++;
    }
    while (src[j] != '\0') {
        new_str[i + j] = src[j];
        j++;
    }
    new_str[i + j] = '\0';
    return new_str;
}
