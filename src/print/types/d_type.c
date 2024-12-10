/*
** EPITECH PROJECT, 2024
** va_my_put_nbr.c
** File description:
** DESCRIPTION
*/

#include "print.h"

static void before(int nb, params_t *a)
{
    if (a->width > 0 && !is_in_flags(a, '-') && !is_in_flags(a, '0'))
        for (int i = 0; i < a->width - int_len(nb); i++) {
            print_char(' ');
        }
    if (is_in_flags(a, '+') && nb >= 0) {
        print_char('+');
        a->width--;
    } else if (is_in_flags(a, ' ') && nb >= 0) {
        print_char(' ');
        a->width--;
    }
    for (int i = 0; i < a->width - int_len(nb) && is_in_flags(a, '0'); i++) {
        print_char('0');
    }
}

static void precision(int nb, params_t *params)
{
    if (params->preci != -1)
        for (int i = 0; i < params->preci - int_len(nb); i++) {
            print_char('0');
        }
}

static void after(int nb, params_t *params)
{
    if (params->width > 0 && is_in_flags(params, '-'))
        for (int i = 0; i < params->width - int_len(nb); i++) {
            print_char(' ');
        }
}

int d_spec(params_t *params)
{
    int nb = va_arg(params->va_args, int);

    before(nb, params);
    precision(nb, params);
    after(nb, params);
    return 0;
}
