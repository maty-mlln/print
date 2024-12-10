/*
** EPITECH PROJECT, 2024
** find_flag.c
** File description:
** DESCRIPTION
*/

#include "print.h"

const char flags[] = {'0', '-', ' ', '+', '*'};

static bool is_valid_nbr(char c)
{
    if (c >= '1' && c <= '9')
        return true;
    return false;
}

static bool is_flag(char c)
{
    for (int i = 0; flags[i] != '\0'; i++)
        if (flags[i] == c)
            return true;
    return false;
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

static char *add_flag(char *flag, char c)
{
    char *new_flag = malloc(sizeof(char) * (str_len(flag) + 2));
    int i = 0;

    for (i = 0; flag[i] != '\0'; i++)
        new_flag[i] = flag[i];
    new_flag[i] = c;
    new_flag[i + 1] = '\0';
    return new_flag;
}

void find_flag(params_t *params)
{
    for (int j = 1; params->format[params->index + j] != '\0' && !is_valid_nbr(params->format[params->index + j]); j++)
        if (is_flag(params->format[params->index + j]))
            params->flag = add_flag(params->flag, params->format[params->index + j]);
}
