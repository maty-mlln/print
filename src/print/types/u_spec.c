/*
** EPITECH PROJECT, 2024
** u_spec.c
** File description:
** DESCRIPTION
*/

#include "print.h"

int u_spec(params_t *va_args)
{
    return print_unsigned_int(va_arg(va_args->va_args, unsigned int));
}
