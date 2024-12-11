/*
** EPITECH PROJECT, 2024
** p_type
** File description:
** DESCRIPTION
*/

#include "print.h"

bool p_type(params_t *params)
{
    params->str = str_add_char(params->str, '%');
    return true;
}
