/*
** EPITECH PROJECT, 2024
** print.c
** File description:
** DESCRIPTION
*/

#include "print.h"

const print_t type[] = {
    {'c', c_spec},
    {'d', d_spec},
    {'i', d_spec},
    {'s', s_spec},
    {'f', f_spec},
    {'F', f_spec},
    {'%', percent_spec},
    {'u', u_spec},
    {'o', o_spec},
    {'p', p_spec},
    {'x', x_spec},
    {'X', x_spec},
    {'e', va_my_put_scinote},
    {'E', va_my_put_scinote},
    {'n', va_my_put_printed_chars_count},
    {'g', va_my_put_scinote_auto},
    {'G', va_my_put_scinote_auto},
};

int run_specifier_function(params_t *params)
{
    for (int j = 0; type[j].specifier != 0; j++) {
        if (type[j].specifier == params->specifier) {
            return (type[j].function(params));
        }
    }
    return 0;
}

void define_struct(params_t *params)
{
    params->flag = malloc(sizeof(char) * 6);
    for (int i = 0; i < 6; i++) {
        params->flag[i] = '\0';
    }
    params->width = 0;
    params->precision = -1;
    params->length = malloc(sizeof(char) * 2);
    params->length[0] = '\0';
    params->specifier = '\0';
}

void apply_format(const char *format, int i, params_t *params)
{
    define_struct(params);
    find_specifier(format, i, params);
    if (params->params_len > 1) {
        find_flag(format, i, params);
        find_width(format, i, params);
        find_precision(format, i, params);
        find_length_modifier(format, i, params);
    }
    params->printed_chars_count += run_specifier_function(params);
}

int print(const char *format, ...)
{
    int temp = 0;
    params_t *params = malloc(sizeof(params_t));

    if (format[0] == '%' && format[1] == '\0')
        return -1;
    va_start(params->args, format);
    params->printed_chars_count = 0;
    for (int i = 0; format[i] != '\0'; i++) {
        params->params_len = 0;
        if (format[i] == '%') {
            apply_format(format, i, params);
            i += params->params_len;
            continue;
        }
        print_char(format[i]);
        params->printed_chars_count++;
    }
    temp = params->printed_chars_count;
    free(params);
    return temp;
}
