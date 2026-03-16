/*
** EPITECH PROJECT, 2025
** precision_parser.c
** File description:
** precision parser function
*/

#include "../my_printf.h"
#include <stddef.h>

const char *get_precision(const char *format, spec_t *spec, va_list args)
{
    int precision = 0;
    size_t i;

    if (!format || format[0] != '.')
        return format;
    if (format[1] == '*') {
        precision = va_arg(args, int);
        if (precision < 0)
            spec->precision = -1;
        else
            spec->precision = precision;
        return &format[2];
    }
    for (i = 1; format[i] >= '0' && format[i] <= '9' && format[i]; i++) {
        precision = precision * 10 + (format[i] - 48);
    }
    spec->precision = precision;
    return &format[i];
}

/*
int main(void)
{
    return 0;
}*/
