/*
** EPITECH PROJECT, 2024
** c_spec.c
** File description:
** DESCRIPTION
*/

#include "print.h"

static void before(params_t *a)
{
    if (a->width > 0 && !is_in_flags(a, '-') && !is_in_flags(a, '0'))
        for (int i = 0; i < a->width - 1; i++) {
            print_char(' ');
        }
}

int c_spec(params_t *va_args)
{
    before(va_args);
    print_char(va_arg(va_args->va_args, int));
    return 0;
}
