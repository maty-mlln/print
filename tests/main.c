/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** DESCRIPTION
*/

#include "utils.h"

int main(void)
{
    char str[100];

    print("--------------------\n");
    print("Hello World!\n");
    print("--------------------\n");
    print("%s Test 1\n", "Hello World!");
    print("--------------------\n");
    print("%010d Test 2\n", 42);
    print("--------------------\n");
    print("%f Test 3\n", 42.42);
    print("--------------------\n");
    print("%c Test 4\n", 'c');
    print("--------------------\n");
    print("%% Test 5\n");
    print("--------------------\n");
    print("%.2f Test 6\n", 42.4242);
    print("--------------------\n");
    sprint(str, "Test : %d", 42);
    print("%s\n", str);
    print("--------------------\n");
    print("Test : %23dHey\n", 23234);
    print("\n");
    return 0;
}
