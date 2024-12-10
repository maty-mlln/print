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

int p_spec(params_t *params);
bool c_type(params_t *params);
int d_spec(params_t *params);
int u_spec(params_t *params);
int s_spec(params_t *params);
int f_spec(params_t *params);
int p_spec(params_t *params);

void parse_spec(params_t *params);
bool parse_flags(params_t *params);
void parse_width(params_t *params);
void parse_preci(params_t *params);

bool is_in_flags(params_t *params, char c);
char *str_add_char(char *str, char c);

#endif /* !PRINT_H */
