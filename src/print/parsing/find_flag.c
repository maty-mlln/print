/*
** EPITECH PROJECT, 2024
** find_flag.c
** File description:
** DESCRIPTION
*/

#include "print.h"

const char flags[] = {'0', '-', ' ', '+', '*'};

static int is_valid_nbr(char c)
{
    if (c >= '1' && c <= '9') {
        return 0;
    }
    return 1;
}

static int is_flag(char c)
{
    for (int i = 0; flags[i] != '\0'; i++) {
        if (c == flags[i]) {
            return 1;
        }
    }
    return 0;
}

int is_in_flags(params_t *struct_args, char c)
{
    for (int i = 0; struct_args->flag[i] != '\0'; i++) {
        if (struct_args->flag[i] == c) {
            return 1;
        }
    }
    return 0;
}

void find_flag(params_t *params)
{
    int list_index = 0;

    for (int j = 1; params->format[params->index + j] != '\0'
        && is_valid_nbr(params->format[params->index + j]); j++) {
        if (is_flag(params->format[params->index + j])) {
            params->flag[list_index] = params->format[params->index + j];
            list_index++;
        }
    }
}
