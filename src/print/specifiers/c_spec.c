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
            a->printed_chars_count++;
        }
}

int c_spec(params_t *args)
{
    before(args);
    print_char(va_arg(args->args, int));
    args->printed_chars_count++;
    return 0;
}
