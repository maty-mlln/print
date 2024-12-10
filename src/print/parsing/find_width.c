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

void find_width(const char *format, int i,
    params_t *struct_args)
{
    char width[10];
    int index;

    for (int j = 1; j < struct_args->params_len; j++) {
        if (format[i + j] == '*' && struct_args->width == 0) {
            struct_args->width = va_arg(struct_args->args, int);
            j++;
            continue;
        }
        if (is_digit(format[i + j]) && format[i + j - 1] != '.'
            && struct_args->width == 0 && format[i + j] != '0') {
            index = j + i;
            find_width_loop(format, index, struct_args, width);
        }
    }
}
