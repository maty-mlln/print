/*
** EPITECH PROJECT, 2024
** is_digits.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

bool is_digits(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    return true;
}
