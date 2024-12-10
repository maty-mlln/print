/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

int main(void)
{
    print("Hello World!\n");
    print("%s\n", "Hello World!");
    print("%d\n", 42);
    print("%f\n", 42.42);
    print("%c\n", 'c');
    print("%s %d %f %c\n", "Hello World!", 42, 42.42, 'c');
    return 0;
}
