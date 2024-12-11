/*
** EPITECH PROJECT, 2024
** va_my_putfloat.c
** File description:
** DESCRIPTION
*/

#include "print.h"

static int define_rounded(double nbr, int preci)
{
    double fractional = nbr - (int)nbr;
    double multiplier = 1;
    int rounded;
    int d;

    for (int j = 0; j < preci; j++)
        multiplier *= 10;
    rounded = fractional * multiplier + 0.5;
    d = (int)rounded;
    if (d >= multiplier)
        d = 0;
    return d;
}

static void before(double nbr, params_t *params)
{
    if (params->width > 0 && !is_in_flags(params, '-')
    && !is_in_flags(params, '0'))
        for (int i = 0; i < params->width - double_len(nbr); i++)
            params->str = str_add_char(params->str, ' ');
    if (is_in_flags(params, '+') && nbr >= 0) {
        params->str = str_add_char(params->str, '+');
        params->width--;
    } else if (is_in_flags(params, ' ') && nbr >= 0) {
        params->str = str_add_char(params->str, ' ');
        params->width--;
    }
    for (int i = 0; i < params->width - double_len(nbr)
    && is_in_flags(params, '0'); i++)
        params->str = str_add_char(params->str, '0');
}

static void format_dec_part(int dec_part, params_t *params)
{
    char *dec_str = int_to_str(dec_part);
    int len = str_len(dec_str);

    for (int i = 0; i < params->preci; i++) {
        if (i < len)
            params->str = str_add_char(params->str, dec_str[i]);
        else
            params->str = str_add_char(params->str, '0');
    }
    free(dec_str);
}

bool f_type(params_t *params)
{
    double nbr = va_arg(params->va_args, double);
    int int_part = (int)nbr;
    char *int_part_str = int_to_str(int_part);
    int dec_part;

    params->preci = (params->preci == -1) ? 6 : params->preci;
    dec_part = define_rounded(nbr, params->preci);
    before(nbr, params);
    params->str = str_cat(params->str, int_part_str);
    free(int_part_str);
    params->str = str_add_char(params->str, '.');
    format_dec_part(dec_part, params);
    return true;
}
