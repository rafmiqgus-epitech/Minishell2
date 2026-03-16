/*
** EPITECH PROJECT, 2025
** get_spec_size.c
** File description:
** compute the size (number of characters) of a parsed specifier
*/

#include "../my_printf.h"
#include <stddef.h>

size_t get_spec_size(spec_t *spec)
{
    return spec->raw_size;
}
