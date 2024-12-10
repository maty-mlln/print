/*
** EPITECH PROJECT, 2024
** print_str.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

int print_str(char *str)
{
    int len = str_len(str);

    write(1, str, len);
    return len;
}
