/*
** EPITECH PROJECT, 2024
** str_add_char.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

char *str_add_char(char *str, char c)
{
    int i = 0;

    if (str == NULL) {
        str = malloc(sizeof(char) * 2);
        if (str == NULL)
            return NULL;
        str[0] = c;
        str[1] = '\0';
        return str;
    }
    str = realloc(str, sizeof(char) * (str_len(str) + 2));
    if (str == NULL)
        return NULL;
    while (str[i] != '\0')
        i++;
    str[i] = c;
    str[i + 1] = '\0';
    return str;
}
