/*
** EPITECH PROJECT, 2024
** find_precision.c
** File description:
** DESCRIPTION
*/

#include "print.h"

void find_precision_loop(const char *format, int index,
    params_t *struct_args, char *precision)
{
    for (int k = 1; k < struct_args->params_len; k++) {
        if (is_digit(format[index + k])) {
            precision[k - 1] = format[index + k];
        } else {
            precision[k - 1] = '\0';
            struct_args->precision = str_to_int(precision);
            break;
        }
    }
}

void find_precision(const char *format, int i, params_t *struct_args)
{
    char precision[10];
    int index;

    for (int j = 1; j < struct_args->params_len; j++) {
        if (format[i + j] == '.' && struct_args->precision == -1) {
            index = j + i;
            struct_args->precision = 0;
            find_precision_loop(format, index, struct_args, precision);
        }
    }
}
