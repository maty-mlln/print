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
    params->str = NULL;
    params->params_len = 0;
    params->flags = NULL;
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

static void free_params(params_t *params)
{
    va_end(params->va_args);
    free(params->str);
    free(params->flags);
    free(params);
}

int format_str(params_t *params)
{
    for (; params->format[params->index] != '\0'; params->index++) {
        if (params->format[params->index] == '%' && apply_format(params))
            continue;
        params->str = str_add_char(params->str, params->format[params->index]);
    }
    return str_len(params->str);
}

int print(const char *format, ...)
{
    params_t *params = init_params();
    size_t len;

    params->format = format;
    va_start(params->va_args, format);
    len = format_str(params);
    print_str(params->str);
    free_params(params);
    return len;
}

int sprint(char *str, const char *format, ...)
{
    params_t *params = init_params();

    params->format = format;
    va_start(params->va_args, format);
    format_str(params);
    str_cpy(str, params->str);
    free_params(params);
    return str_len(str);
}
