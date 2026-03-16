/*
** EPITECH PROJECT, 2025
** err_result_pattern_design.c
** File description:
** error result pattern design
*/

#include "result_pattern_design.h"
#include <stdbool.h>
#include <stddef.h>

result_int_t err_int(const char *msg)
{
    result_int_t r = (result_int_t){ .ok = false };

    r.data.error_msg = msg;
    return r;
}

result_size_t err_size(const char *msg)
{
    result_size_t r = (result_size_t){ .ok = false };

    r.data.error_msg = msg;
    return r;
}

result_char_t err_char(const char *msg)
{
    result_char_t r = (result_char_t){ .ok = false };

    r.data.error_msg = msg;
    return r;
}

result_string_t err_string(const char *msg)
{
    result_string_t r = (result_string_t){ .ok = false };

    r.data.error_msg = msg;
    return r;
}

result_string_array_t err_string_array(const char *msg)
{
    result_string_array_t r = (result_string_array_t){ .ok = false };

    r.data.error_msg = msg;
    return r;
}
