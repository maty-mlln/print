/*
** EPITECH PROJECT, 2024
** parse_width.c
** File description:
** DESCRIPTION
*/

#include "utils.h"
#include "print.h"

static void extract_width(params_t *params, int j)
{
    char width[params->params_len - 1];

    for (int k = 0; k < params->params_len; k++) {
        if (is_digit(params->format[j + k + params->index]))
            width[k] = params->format[j + k + params->index];
        else {
            width[k] = '\0';
            params->width = str_to_int(width);
            return;
        }
    }
}

void parse_width(params_t *params)
{
    for (int j = 1; j < params->params_len; j++) {
        if (is_digit(params->format[params->index + j])
        && params->format[params->index + j - 1] != '.'
        && params->width == 0 && params->format[params->index + j] != '0') {
            extract_width(params, j);
            return;
        }
    }
}
