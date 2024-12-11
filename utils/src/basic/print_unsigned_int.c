/*
** EPITECH PROJECT, 2024
** print_unsigned_int.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

int print_unsigned_int(unsigned int nb)
{
    int count = 0;

    if (nb >= 10)
        count += print_unsigned_int(nb / 10);
    print_char('0' + (nb % 10));
    return count + 1;
}
