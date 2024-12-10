/*
** EPITECH PROJECT, 2024
** parse_flags.c
** File description:
** DESCRIPTION
*/

#include "print.h"

static bool is_valid_nbr(char c)
{
    if (c >= '1' && c <= '9')
        return true;
    return false;
}

static bool is_flag(char c)
{
    const char flags[] = {'0', '-', ' ', '+'};

    for (int i = 0; flags[i] != '\0'; i++)
        if (flags[i] == c)
            return true;
    return false;
}

bool is_in_flags(params_t *params, char c)
{
    for (int i = 0; params->flags[i] != '\0'; i++) {
        if (params->flags[i] == c) {
            return true;
        }
    }
    return false;
}

bool parse_flags(params_t *params)
{
    for (int j = 1; j < params->params_len; j++) {
        if (is_valid_nbr(params->format[params->index + j]))
            return true;
        if (is_in_flags(params, params->format[params->index + j]))
            return false;
        if (is_flag(params->format[params->index + j]))
            params->flags = str_add_char(params->flags,
                params->format[params->index + j]);
    }
    return true;
}
