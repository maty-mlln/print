/*
** EPITECH PROJECT, 2024
** double_len.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

int double_len(double f)
{
    int len = 0;

    if (f < 0) {
        len++;
        f *= -1;
    }
    len += int_len((int)f);
    len++;
    len += 6;
    return len;
}
