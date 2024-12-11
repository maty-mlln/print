/*
** EPITECH PROJECT, 2024
** str_add_char.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

char *str_add_char(char *str, char c)
{
    char *new_str = malloc(sizeof(char) * (str_len(str) + 2));
    int i = 0;

    if (new_str == NULL)
        return NULL;
    if (str == NULL) {
        new_str[0] = c;
        new_str[1] = '\0';
        free(str);
        return new_str;
    }
    for (; str[i] != '\0'; i++)
        new_str[i] = str[i];
    free(str);
    new_str[i] = c;
    new_str[i + 1] = '\0';
    return new_str;
}
