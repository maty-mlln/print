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

int char_arr_len(char **arr);
char *llint_to_base(long long int nbr, char const *base);
char *int_to_base(int nbr, char const *base);
char *uint_to_base(unsigned int nbr, char const *base);
int print_unsigned_int(unsigned int nb);
int double_len(double f);
int print_str(char *str);
char *rev_str(char *str);
int print_int(int nb);
bool is_digit(const char c);
bool is_digits(char *str);
char *str_dup(char const *src);
int str_cmp(const char *str1, const char *str2);
int print(const char *format, ...);
int str_len(char const *str);
void print_char(char c);
int str_to_int(char *str);
int int_len(int nb);

#endif /* !UTILS_H */
