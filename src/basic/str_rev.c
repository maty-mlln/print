/*
** EPITECH PROJECT, 2024
** str_rev.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

char *str_rev(char *str)
{
    int i = 0;
    int j = str_len(str) - 1;
    char tmp;

    while (i < j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return (str);
}
