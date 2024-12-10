/*
** EPITECH PROJECT, 2024
** int_len.c
** File description:
** DESCRIPTION
*/

int int_len(int nb)
{
    int len = 0;

    for (; nb > 0; len++)
        nb /= 10;
    return len;
}
