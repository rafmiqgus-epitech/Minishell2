/*
** EPITECH PROJECT, 2025
** result_pattern_design.c
** File description:
** ok result pattern design functions
*/

#include "result_pattern_design.h"
#include <stdbool.h>
#include <stddef.h>

result_int_t ok_int(int val)
{
    result_int_t r = (result_int_t){ .ok = true };

    r.data.value = val;
    return r;
}

result_size_t ok_size(size_t val)
{
    result_size_t r = (result_size_t){ .ok = true };

    r.data.size = val;
    return r;
}

result_char_t ok_char(char val)
{
    result_char_t r = (result_char_t){ .ok = true };

    r.data.c = val;
    return r;
}

result_string_t ok_string(char *val)
{
    result_string_t r = (result_string_t){ .ok = true };

    r.data.string = val;
    return r;
}

result_string_array_t ok_string_array(char **val)
{
    result_string_array_t r = (result_string_array_t){ .ok = true };

    r.data.array = val;
    return r;
}
