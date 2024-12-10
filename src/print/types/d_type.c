/*
** EPITECH PROJECT, 2024
** va_my_put_nbr.c
** File description:
** DESCRIPTION
*/

#include "print.h"

static void before(int nb, params_t *params)
{
    if (params->width > 0 && !is_in_flags(params, '-')
    && !is_in_flags(params, '0'))
        for (int i = 0; i < params->width - int_len(nb); i++)
            params->str = str_add_char(params->str, ' ');
    if (is_in_flags(params, '+') && nb >= 0) {
        params->str = str_add_char(params->str, '+');
        params->width--;
    } else if (is_in_flags(params, ' ') && nb >= 0) {
        params->str = str_add_char(params->str, ' ');
        params->width--;
    }
    for (int i = 0; i < params->width - int_len(nb)
    && is_in_flags(params, '0'); i++)
        params->str = str_add_char(params->str, '0');
}

static void preci(int nb, params_t *params)
{
    if (params->preci)
        for (int i = 0; i < params->preci - int_len(nb); i++)
            params->str = str_add_char(params->str, '0');
}

static void after(int nb, params_t *params)
{
    if (params->width > 0 && is_in_flags(params, '-'))
        for (int i = 0; i < params->width - int_len(nb); i++)
            params->str = str_add_char(params->str, ' ');
}

bool d_type(params_t *params)
{
    int nb = va_arg(params->va_args, int);

    before(nb, params);
    params->str = str_cat(params->str, int_to_str(nb));
    preci(nb, params);
    after(nb, params);
    return true;
}
