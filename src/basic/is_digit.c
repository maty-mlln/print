/*
** EPITECH PROJECT, 2024
** is_digit.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

bool is_digit(const char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}
