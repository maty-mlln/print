/*
** EPITECH PROJECT, 2024
** print.h
** File description:
** Header file for my library
*/

#ifndef PRINT_H
    #define PRINT_H

    #include "utils.h"

typedef struct params_s {
    int index;
    const char *format;
    char *str;
    int params_len;
    va_list va_args;
    char *flag;
    int width;
    int precision;
    char *length;
    char specifier;
} params_t;

int p_spec(params_t *params);
int c_spec(params_t *params);
int d_spec(params_t *params);
int u_spec(params_t *params);
int s_spec(params_t *params);
int f_spec(params_t *params);
int p_spec(params_t *params);

void find_width_loop(const char *format, int i, params_t *params, char *width);
int is_in_flags(params_t *params, char c);
void parse_spec(params_t *params);
void find_flag(params_t *params);
void find_width(params_t *params);
void find_precision(params_t *params);

#endif /* !PRINT_H */
