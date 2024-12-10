/*
** EPITECH PROJECT, 2024
** va_print_str.c
** File description:
** DESCRIPTION
*/

#include "print.h"

static void my_put_str(char *str, params_t *a)
{
    a->precision = (a->precision == -1) ? str_len(str) : a->precision;
    for (int i = 0; str[i] != '\0' && i < a->precision; i++) {
        print_char(str[i]);
        a->printed_chars_count++;
    }
}

static char *is_null(char *str)
{
    if (str == NULL)
        str = str_dup("(null)");
    return str;
}

static void before(char *str, params_t *a)
{
    if (!is_in_flags(a, '-') && !is_in_flags(a, '0'))
        for (int i = 0; i < a->width - str_len(str); i++) {
            print_char(' ');
            a->printed_chars_count++;
        }
}

int s_spec(params_t *params)
{
    char *str = va_arg(params->args, char *);

    str = is_null(str);
    before(str, params);
    my_put_str(str, params);
    return 0;
}
