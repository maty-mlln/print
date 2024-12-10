/*
** EPITECH PROJECT, 2024
** print_int.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

int print_int(int nb)
{
    int i = 0;
    char buffer[12];
    int neg = (nb < 0) ? 1 : 0;

    if (nb == 0)
        return (write(1, "0", 1));
    if (neg) {
        write(1, "-", 1);
        nb = -nb;
    }
    while (nb > 0) {
        buffer[i] = (nb % 10) + '0';
        i++;
        nb /= 10;
    }
    for (int j = i - 1; j >= 0; j--)
        write(1, &buffer[j], 1);
    return (i + neg);
}
