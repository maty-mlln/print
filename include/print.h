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
    int params_len;
    int printed_chars_count;
    va_list args;
    char *flag;
    int width;
    int precision;
    char *length;
    char specifier;
} params_t;

typedef struct print_s {
    char specifier;
    int (*function)(params_t *params);
} print_t;

int va_my_put_unsigned_dec(params_t *params);
int p_spec(params_t *params);
int o_spec(params_t *params);
int x_spec(params_t *params);
int c_spec(params_t *params);
int d_spec(params_t *params);
int u_spec(params_t *params);
int s_spec(params_t *params);
int f_spec(params_t *params);
int percent_spec(params_t *params);
int va_my_put_scinote(params_t *params);
int va_my_put_printed_chars_count(params_t *params);
int va_my_put_a_specifier(params_t *params);
int va_my_put_scinote_auto(params_t *params);

void find_width_loop(const char *format, int i, params_t *params, char *width);
int is_in_flags(params_t *params, char c);
void find_specifier(const char *format, int i, params_t *params);
void find_flag(const char *format, int i, params_t *params);
void find_width(const char *format, int i, params_t *params);
void find_precision(const char *format, int i, params_t *params);
void find_length_modifier(const char *format, int i, params_t *params);

#endif /* !PRINT_H */
