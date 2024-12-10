/*
** EPITECH PROJECT, 2024
** parse_preci.c
** File description:
** DESCRIPTION
*/

#include "print.h"

static void extract_precision(params_t *params, char *precision, int j)
{
    for (int k = 0; k < params->params_len; k++)
        if (is_digit(params->format[j + k])) {
            precision[k] = params->format[j + k];
        } else {
            precision[k] = '\0';
            params->preci = str_to_int(precision);
            return;
        }
}

void parse_preci(params_t *params)
{
    char precision[params->params_len - 1];

    for (int j = 1; j < params->params_len; j++)
        if (params->format[params->index + j] == '.' && !params->preci) {
            extract_precision(params, precision, params->index + j + 1);
            return;
        }
}
