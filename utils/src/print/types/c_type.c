/*
** EPITECH PROJECT, 2024
** c_type.c
** File description:
** DESCRIPTION
*/

#include "print.h"

bool c_type(params_t *params)
{
    if (params->width > 0 && !is_in_flags(params, '-')
    && !is_in_flags(params, '0'))
        for (int i = 0; i < params->width - 1; i++)
            params->str = str_add_char(params->str, ' ');
    params->str = str_add_char(params->str, va_arg(params->va_args, int));
    if (params->width > 0 && is_in_flags(params, '-')
    && !is_in_flags(params, '0'))
        for (int i = 0; i < params->width - 1; i++)
            params->str = str_add_char(params->str, ' ');
    return true;
}
