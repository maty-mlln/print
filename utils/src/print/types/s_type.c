/*
** EPITECH PROJECT, 2024
** va_print_str.c
** File description:
** DESCRIPTION
*/

#include "print.h"

bool s_type(params_t *params)
{
    char *str = va_arg(params->va_args, char *);

    if (str == NULL) {
        str = str_dup("(null)");
        return true;
    }
    if (!is_in_flags(params, '-') && !is_in_flags(params, '0'))
        for (int i = 0; i < params->width - str_len(str); i++)
            params->str = str_add_char(params->str, ' ');
    params->str = str_cat(params->str, str);
    return true;
}
