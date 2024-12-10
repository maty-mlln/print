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
    params->flag = NULL;
    params->width = 0;
    params->precision = 0;
    params->length = NULL;
    params->specifier = 0;
    return params;
}

bool run_specifier_function(params_t *params)
{
    switch (params->specifier) {
        case 'c':
            return c_spec(params);
        case 's':
            return s_spec(params);
        case 'd':
            return d_spec(params);
        case 'i':
            return d_spec(params);
        case 'u':
            return u_spec(params);
        case 'p':
            return p_spec(params);
        case 'f':
            return f_spec(params);
        case '%':
            return p_spec(params);
        default:
            return 0;
    }
}

static void apply_format(params_t *params)
{
    params->params_len = 0;
    parse_spec(params);
    printf("params_len: %d\n", params->params_len);
    printf("specifier: %c\n", params->specifier);
    // if (params->params_len > 2) {
    //     find_flag(params);
    //     printf("flag: %s\n", params->flag);
    //     // find_width(params);
    //     // find_precision(params);
    // }
    params->index += params->params_len;
    // run_specifier_function(params);
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

int print(const char *format, ...)
{
    params_t *params = init_params();

    va_start(params->va_args, format);
    params->format = str_dup(format);
    for (; format[params->index] != '\0'; params->index++)
        if (format[params->index] == '%')
            apply_format(params);
        else
            params->str = str_add_char(params->str, format[params->index]);
    print_str(params->str);
    va_end(params->va_args);
    free(params);
    return 0;
}
