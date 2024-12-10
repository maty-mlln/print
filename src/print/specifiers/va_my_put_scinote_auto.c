/*
** EPITECH PROJECT, 2024
** va_my_put_scinote_auto.c
** File description:
** DESCRIPTION
*/

#include "utils.h"
#include "print.h"

int my_put_double_auto(double f)
{
    int integer_part = (int)f;
    int decimal_part = (f - integer_part) * 1000000;
    int sum = 0;

    for (int i = 0; decimal_part % 10 == 0; i++)
        decimal_part /= 10;
    for (int j = 0; int_len(decimal_part) > 5; j++)
        decimal_part /= 10;
    sum += print_int(integer_part);
    print_char('.');
    return sum + print_int(decimal_part) + 1;
}

static int my_double_len(double f)
{
    int integer_part = (int)f;
    int decimal_part = (f - integer_part) * 1000000;
    int sum = 0;

    for (int i = 0; decimal_part % 10 == 0; i++)
        decimal_part /= 10;
    for (int j = 0; int_len(decimal_part) > 5; j++)
        decimal_part /= 10;
    sum += int_len(integer_part);
    sum++;
    sum += int_len(decimal_part);
    return (sum);
}

int condition1(params_t *args, double f, int f_len)
{
    my_put_double_auto(f);
    for (int i = 0; i < args->width - f_len; i++)
        print_char(' ');
    return (args->width > double_len(f) ? args->width : double_len(f));
}

int condition2(params_t *args, double f, int f_len)
{
    for (int i = 0; i < args->width - f_len; i++)
        print_char('0');
    my_put_double_auto(f);
    return (args->width);
}

int condition3(params_t *args, double f, int f_len)
{
    for (int i = 0; i < args->width - f_len; i++)
        print_char(' ');
    my_put_double_auto(f);
    return (args->width);
}

int va_my_put_scinote_auto(params_t *a)
{
    double f = va_arg(a->args, double);
    int f_len = my_double_len(f);

    if (is_in_flags(a, '-'))
        return condition1(a, f, f_len);
    if (a->width > 0 && is_in_flags(a, '0'))
        return condition2(a, f, f_len);
    if (a->width > 0)
        return condition3(a, f, f_len);
    if ((is_in_flags(a, ' ') && f >= 0) || (is_in_flags(a, '+') && f < 0)) {
        print_char(' ');
        my_put_double_auto(f);
        return (f_len + 1);
    }
    if (is_in_flags(a, '+')) {
        print_char('+');
        my_put_double_auto(f);
        return (f_len + 1);
    }
    return my_put_double_auto(f);
}
