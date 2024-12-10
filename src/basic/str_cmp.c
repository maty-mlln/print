/*
** EPITECH PROJECT, 2024
** str_cmp.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

int str_cmp(const char *str1, const char *str2)
{
    int i = 0;

    for (; str1[i] && str2[i]; i++) {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
    }
    return str1[i] - str2[i];
}
