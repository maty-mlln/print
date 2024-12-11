/*
** EPITECH PROJECT, 2024
** u_type.c
** File description:
** DESCRIPTION
*/

#include "print.h"

static void before(unsigned nb, params_t *params)
{
    if (params->width > 0 && !is_in_flags(params, '-')
    && !is_in_flags(params, '0'))
        for (int i = 0; i < params->width - int_len(nb); i++)
            params->str = str_add_char(params->str, ' ');
    for (int i = 0; i < params->width - int_len(nb)
    && is_in_flags(params, '0'); i++)
        params->str = str_add_char(params->str, '0');
}

static void preci(unsigned nb, params_t *params)
{
    if (params->preci)
        for (int i = 0; i < params->preci - int_len(nb); i++)
            params->str = str_add_char(params->str, '0');
}

static void after(unsigned nb, params_t *params)
{
    if (params->width > 0 && is_in_flags(params, '-'))
        for (int i = 0; i < params->width - int_len(nb); i++)
            params->str = str_add_char(params->str, ' ');
}

bool u_type(params_t *params)
{
    unsigned nb = va_arg(params->va_args, unsigned);

    before(nb, params);
    params->str = str_cat(params->str, uint_to_str(nb));
    preci(nb, params);
    after(nb, params);
    return true;
}
