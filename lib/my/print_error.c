/*
** EPITECH PROJECT, 2025
** print_error.c
** File description:
** prints to stderr based on a string
*/

#include "my.h"
#include <unistd.h>

int print_error(const char *err_msg)
{
    return write(2, err_msg, my_strlen(err_msg));
}
