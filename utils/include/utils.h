/*
** EPITECH PROJECT, 2024
** utils_lib.h
** File description:
** DESCRIPTION
*/

#ifndef UTILS_H
    #define UTILS_H

    #include <stdarg.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <unistd.h>

// Converters
char *llint_to_base(long long int nbr, char const *base);
char *int_to_base(int nbr, char const *base);
char *uint_to_base(unsigned int nbr, char const *base);
int str_to_int(char *str);
char *int_to_str(int nb);
char *uint_to_str(unsigned int nb);

// ASCII Identifiers
bool is_digit(const char c);
bool is_digits(char *str);

// String Manipulators
char *str_cpy(char *dest, char *src);
int sprint(char *str, const char *format, ...);
char *str_add_char(char *str, char c);
char *str_rev(char *str);
char *str_dup(char *src);
int str_cmp(const char *str1, const char *str2);
char *str_cat(char *dest, char *src);

// Printers
int print(const char *format, ...);
int print_char(const char c);
int print_str(char *str);
int print_int(int nb);
int print_unsigned_int(unsigned int nb);

// Lengths Identifiers
int int_len(int nb);
int str_len(char const *str);
int double_len(double f);
int char_arr_len(char **arr);

#endif /* !UTILS_H */
