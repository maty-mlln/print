/*
** EPITECH PROJECT, 2024
** char_arr_len.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

int char_arr_len(char **arr)
{
    int len = 0;

    for (; arr[len] != NULL; len++);
    return len;
}
