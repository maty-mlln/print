/*
** EPITECH PROJECT, 2024
** print.h
** File description:
** Header file for my library
*/

#ifndef PRINT_H
    #define PRINT_H

    #include "utils.h"
    #include <stdio.h>

typedef struct params_s {
    int index;
    const char *format;
    char *str;
    int params_len;
    va_list va_args;
    char *flags;
    int width;
    int preci;
    char *length;
    char specifier;
} params_t;

bool c_type(params_t *params);
bool d_type(params_t *params);
bool u_type(params_t *params);
bool s_type(params_t *params);
bool f_type(params_t *params);
bool p_type(params_t *params);

void parse_spec(params_t *params);
bool parse_flags(params_t *params);
void parse_width(params_t *params);
void parse_preci(params_t *params);

bool is_in_flags(params_t *params, char c);
char *str_add_char(char *str, char c);

#endif /* !PRINT_H */
