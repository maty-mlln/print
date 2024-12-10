/*
** EPITECH PROJECT, 2024
** p_spec.c
** File description:
** DESCRIPTION
*/

#include "print.h"

int p_spec(params_t *params)
{
    long long int ptr = va_arg(params->args, long long int);

    if (!ptr)
        return print_str("(nil)") + 5;
    if (is_in_flags(params, '-') && params->width > 0) {
        print_str("0x");
        print_str(llint_to_base(ptr, "0123456789abcdef"));
        for (int i = 0; i < params->width - 14; i++)
            print_char(' ');
        return 14 + params->width;
    }
    if (params->width > 0) {
        for (int i = 0; i < params->width - 14; i++)
            print_char(' ');
    }
    print_str("0x");
    print_str(llint_to_base(ptr, "0123456789abcdef"));
    return 14 + params->width;
}
