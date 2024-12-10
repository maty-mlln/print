/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

int main(void)
{
    print("--------------------\n");
    print("Hello World!\n");
    print("--------------------\n");
    print("%s Test 1\n", "Hello World!");
    print("--------------------\n");
    print("%023d Test 2\n", 42);
    print("--------------------\n");
    print("%-23f Test 3\n", 42.42);
    print("--------------------\n");
    print("%c Test 4\n", 'c');
    print("--------------------\n");
    return 0;
}
