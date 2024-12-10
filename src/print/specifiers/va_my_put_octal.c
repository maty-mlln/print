/*
** EPITECH PROJECT, 2024
** va_print_str.c
** File description:
** DESCRIPTION
*/

#include "print.h"

int o_spec(params_t *params)
{
    int sum = 0;
    int nbr = va_arg(params->args, int);

    if (is_in_flags(params, '#') && nbr != 0) {
        print_char('0');
        sum++;
    }
    sum += print_str(int_to_base(nbr, "01234567"));
    return sum;
}
