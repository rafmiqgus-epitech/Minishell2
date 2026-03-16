/*
** EPITECH PROJECT, 2025
** type_verification.c
** File description:
** functions to verify of what type is the content of a string
*/

#include <stdbool.h>
#include <stddef.h>


bool is_int_char(char c)
{
    if (!(c >= '0' && c <= '9'))
        return false;
    return true;
}

bool is_int_str(const char *str)
{
    for (size_t i = 0; str[i]; i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return false;
    }
    return true;
}

int str_to_int(const char *str)
{
    int res = 0;

    for (size_t i = 0; str[i]; i++) {
        res *= 10;
        res += str[i] - 48;
    }
    return res;
}
