/*
** EPITECH PROJECT, 2024
** va_print_str.c
** File description:
** DESCRIPTION
*/

#include "utils.h"
#include "print.h"

char *my_uint_base_str(unsigned int nbr, char const *base)
{
    int base_len = str_len(base);
    int i = 0;
    char *str = malloc(sizeof(char) * 100);

    if (nbr != 0) {
        while (nbr != 0) {
            str[i] = base[nbr % base_len];
            nbr = nbr / base_len;
            i++;
        }
    } else {
        str[i] = '0';
        i++;
    }
    str[i] = '\0';
    return (rev_str(str));
}

int x_spec(params_t *params)
{
    char *str = malloc(sizeof(char) * 100);
    char *base_min = "0123456789abcdef";
    char *base_maj = "0123456789ABCDEF";

    if (params->specifier == 'X')
        str = my_uint_base_str(va_arg(params->args, unsigned), base_maj);
    if (params->specifier == 'x')
        str = my_uint_base_str(va_arg(params->args, unsigned), base_min);
    if (is_in_flags(params, '#')) {
        params->width -= print_str("0x");
        params->printed_chars_count += 2;
    }
    for (int i = 0; i < params->width - str_len(str); i++) {
        print_char('0');
        params->printed_chars_count++;
    }
    print_str(str);
    params->printed_chars_count += str_len(str);
    free(str);
    return 0;
}
