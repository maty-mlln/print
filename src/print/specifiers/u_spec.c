/*
** EPITECH PROJECT, 2024
** u_spec.c
** File description:
** DESCRIPTION
*/

#include "print.h"

int u_spec(params_t *args)
{
    return print_unsigned_int(va_arg(args->args, unsigned int));
}
