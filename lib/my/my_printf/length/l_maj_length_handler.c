/*
** EPITECH PROJECT, 2025
** l_maj_length_handler.c
** File description:
** handler for L length modifier
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


char *l_maj_length_handler(spec_t *spec, va_list args, size_t size)
{
    char *str = NULL;

    if (is_in_char(spec->specifier, "fFeEgGaA")) {
        str = format_float_spec(spec, va_arg(args, long double));
        return safe_return(str);
    }
    return default_length_handler(spec, args, size);
}
