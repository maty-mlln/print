/*
** EPITECH PROJECT, 2024
** print.c
** File description:
** DESCRIPTION
*/

#include "print.h"

static params_t *init_params(void)
{
    params_t *params = malloc(sizeof(params_t));

    if (params == NULL)
        return NULL;
    params->index = 0;
    params->format = NULL;
    params->str = str_dup("");
    params->params_len = 0;
    params->flags = str_dup("");
    params->width = 0;
    params->preci = -1;
    params->specifier = 0;
    return params;
}

bool run_specifier_function(params_t *params)
{
    switch (params->specifier) {
        case 'c':
            return c_type(params);
        case 's':
            return s_type(params);
        case 'd':
            return d_type(params);
        case 'u':
            return u_type(params);
        case 'f':
            return f_type(params);
        case '%':
            return p_type(params);
        default:
            return 0;
    }
}

static bool apply_format(params_t *params)
{
    params->params_len = 0;
    parse_spec(params);
    if (params->params_len > 2) {
        if (!parse_flags(params))
            return false;
        parse_width(params);
        parse_preci(params);
    }
    run_specifier_function(params);
    params->index += params->params_len - 1;
    return true;
}

char *str_add_char(char *str, char c)
{
    char *new_str = malloc(sizeof(char) * (str_len(str) + 2));
    int i = 0;

    if (new_str == NULL)
        return NULL;
    for (; str[i] != '\0'; i++)
        new_str[i] = str[i];
    new_str[i] = c;
    new_str[i + 1] = '\0';
    free(str);
    return new_str;
}

static void free_params(params_t *params)
{
    free(params->str);
    free(params->flags);
    free(params);
}

int print(const char *format, ...)
{
    params_t *params = init_params();

    va_start(params->va_args, format);
    params->format = format;
    for (; format[params->index] != '\0'; params->index++) {
        if (format[params->index] == '%' && apply_format(params))
            continue;
        params->str = str_add_char(params->str, format[params->index]);
    }
    print_str(params->str);
    va_end(params->va_args);
    free_params(params);
    return 0;
}
