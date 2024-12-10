/*
** EPITECH PROJECT, 2024
** va_my_put_scinote.c
** File description:
** DESCRIPTION
*/

#include "print.h"

static int check_exponent(int exponent)
{
    if (exponent >= 0) {
        print_char('+');
    } else {
        print_char('-');
        exponent = -exponent;
    }
    return exponent;
}

static void check_if_majmin(params_t *args)
{
    if (args->specifier == 'e')
        print_char('e');
    else
        print_char('E');
}

static void loop(int *sum, double *num)
{
    for (int i = 0; i < 6; i++) {
        *num *= 10.0;
        print_char((int)*num + '0');
        *sum += 1;
        *num -= (int)*num;
    }
}

static void loop_2(double *num, int *exponent)
{
    while (*num >= 10.0) {
        *num /= 10.0;
        *exponent += 1;
    }
    while (*num > 0.0 && *num < 1.0) {
        *num *= 10.0;
        *exponent -= 1;
    }
}

int va_my_put_scinote(params_t *args)
{
    int sum = 0;
    double num = va_arg(args->args, double);
    int exponent = 0;

    loop_2(&num, &exponent);
    print_char((int)num + '0');
    print_char('.');
    num -= (int)num;
    num += 0.0000005;
    loop(&sum, &num);
    check_if_majmin(args);
    check_exponent(exponent);
    if (exponent < 10) {
        print_char('0');
        sum++;
    }
    print_int(exponent);
    return sum + 4 + int_len(exponent);
}
