/*
** EPITECH PROJECT, 2024
** str_len
** File description:
** DESCRIPTION
*/

#include <stdlib.h>

int str_len(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}
