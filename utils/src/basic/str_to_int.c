/*
** EPITECH PROJECT, 2024
** str_to_int.c
** File description:
** DESCRIPTION
*/

int str_to_int(char *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        res = res * 10 + str[i] - '0';
    }
    return res;
}
