/*
** EPITECH PROJECT, 2024
** find_width.c
** File description:
** DESCRIPTION
*/

#include "utils.h"
#include "print.h"

void find_width_loop(const char *format, int index,
    params_t *struct_args, char *width)
{
    for (int k = 0; k < struct_args->params_len; k++) {
        if (is_digit(format[index + k])) {
            width[k] = format[index + k];
        } else {
            width[k] = '\0';
            struct_args->width = str_to_int(width);
            break;
        }
    }
}

void find_width(params_t *params)
{
    char width[10];
    int index;

    for (int j = 1; j < params->params_len; j++) {
        if (params->format[params->index + j] == '*' && params->width == 0) {
            params->width = va_arg(params->va_args, int);
            j++;
            continue;
        }
        if (is_digit(params->format[params->index + j]) && params->format[params->index + j - 1] != '.'
            && params->width == 0 && params->format[params->index + j] != '0') {
            index = j + params->index;
            find_width_loop(params->format, index, params, width);
        }
    }
}
