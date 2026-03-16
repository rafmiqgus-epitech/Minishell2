/*
** EPITECH PROJECT, 2025
** get_spec_content.c
** File description:
** functions to get the the size of the content of a given spec
*/

#include "../my_printf.h"
#include "../../result_pattern_design.h"
#include <stdarg.h>

result_string_t get_spec_content(spec_t *spec, va_list args, size_t size)
{
    result_string_t raw_content = get_specifier_content(spec, args, size);
    result_string_t spec_content;
    result_string_t full_content;

    if (raw_content.ok == false)
        return err_string("Something went wrong while getting spec content");
    spec_content = apply_precision(raw_content.data.string, spec);
    if (spec_content.ok == false)
        return err_string("Something went wrong while applying precision");
    full_content = apply_formatting(spec_content.data.string, spec);
    if (full_content.ok == false)
        return err_string("Something went wrong while formatting content");
    return ok_string(full_content.data.string);
}
