/*
** EPITECH PROJECT, 2025
** my_putchar.c
** File description:
** my_putchar.c
*/

#include <unistd.h>

int my_putchar(char *c)
{
    return write(1, &c, 1);
}
