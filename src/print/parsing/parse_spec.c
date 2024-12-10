/*
** EPITECH PROJECT, 2024
** parse_spec.c
** File description:
** DESCRIPTION
*/

#include "print.h"

static bool is_specifier(char c)
{
    const char specs[] = {'c', 'd', 'i', 's', 'f', '%', 'u'};

    for (int i = 0; specs[i] != '\0'; i++)
        if (c == specs[i])
            return true;
    return false;
}

void parse_spec(params_t *params)
{
    for (int j = 1; params->format[params->index + j] != '\0'; j++)
        if (is_specifier(params->format[params->index + j])) {
            params->specifier = params->format[params->index + j];
            params->params_len = j + 1;
            return;
        }
}
