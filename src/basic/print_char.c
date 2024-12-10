/*
** EPITECH PROJECT, 2024
** print_char.c
** File description:
** DESCRIPTION
*/

#include <unistd.h>

void print_char(const char c)
{
    write(1, &c, 1);
}
