/*
** EPITECH PROJECT, 2025
** j_length_handler.c
** File description:
** handler for j length modifier
*/

#include "../../my.h"
#include "../my_printf.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>

static const char *get_base(char specifier)
{
    if (specifier == 'o')
        return "01234567";
    if (specifier == 'u')
        return "0123456789";
    if (specifier == 'x')
        return "0123456789abcdef";
    if (specifier == 'X')
        return "0123456789ABCDEF";
    return NULL;
}

static char *j_unsigned_handler(char specifier, va_list args)
{
    const char *base = get_base(specifier);

    if (!base)
        return NULL;
    return safe_return(utoa_base(va_arg(args, uintmax_t), base));
}

char *j_length_handler(spec_t *spec, va_list args, size_t size)
{
    char *str = NULL;

    if (is_in_char(spec->specifier, "di"))
        return safe_return(signed_to_str(va_arg(args, intmax_t)));
    str = j_unsigned_handler(spec->specifier, args);
    if (str)
        return str;
    return default_length_handler(spec, args, size);
}
