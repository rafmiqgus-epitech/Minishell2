/*
** EPITECH PROJECT, 2025
** specifier_parser.c
** File description:
** specifier parser function
*/

#include "../my_printf.h"
#include <stddef.h>

static bool is_specifier(char c)
{
    const char *specifiers = "csdiouxXpnfFeEgGaA%";

    for (int i = 0; specifiers[i]; i++) {
        if (c == specifiers[i])
            return true;
    }
    return false;
}

void get_specifier(const char *format, spec_t *spec)
{
    if (is_specifier(*format)) {
        spec->specifier = *format;
    }
}
