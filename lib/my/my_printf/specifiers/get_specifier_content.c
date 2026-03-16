/*
** EPITECH PROJECT, 2025
** get_specifier_content.c
** File description:
** functions to get the content of a specifier based on a spec_t and a va_list
*/

#include "../my_printf.h"
#include "../../result_pattern_design.h"
#include "../../my.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

static result_string_t pointer_handler(void *ptr)
{
    unsigned long addr = (unsigned long)ptr;
    char *hex_addr = my_int_to_base(addr, "0123456789abcdef");
    char *ptr_str = NULL;
    size_t len = 0;

    if (!hex_addr)
        return err_string("Pointer conversion failed");
    len = my_strlen(hex_addr);
    ptr_str = malloc(len + 1);
    if (!ptr_str) {
        free(hex_addr);
        return err_string("Pointer allocation failed");
    }
    my_strcpy(ptr_str, hex_addr);
    free(hex_addr);
    return ok_string(ptr_str);
}

static result_string_t char_handler(char c)
{
    char *str = malloc(2);

    if (!str)
        return err_string("Char allocation failed");
    str[0] = c;
    str[1] = '\0';
    return ok_string(str);
}

static bool set_n_short(spec_t *spec, va_list args, size_t size)
{
    if (my_strcmp(spec->length, "hh") == 0) {
        *va_arg(args, signed char *) = (signed char)size;
        return true;
    }
    if (my_strcmp(spec->length, "h") == 0) {
        *va_arg(args, short *) = (short)size;
        return true;
    }
    return false;
}

static bool set_n_long(spec_t *spec, va_list args, size_t size)
{
    if (my_strcmp(spec->length, "ll") == 0) {
        *va_arg(args, long long *) = (long long)size;
        return true;
    }
    if (my_strcmp(spec->length, "l") == 0) {
        *va_arg(args, long *) = (long)size;
        return true;
    }
    return false;
}

static bool set_n_special(spec_t *spec, va_list args, size_t size)
{
    if (my_strcmp(spec->length, "j") == 0) {
        *va_arg(args, intmax_t *) = (intmax_t)size;
        return true;
    }
    if (my_strcmp(spec->length, "z") == 0) {
        *va_arg(args, size_t *) = size;
        return true;
    }
    if (my_strcmp(spec->length, "t") == 0) {
        *va_arg(args, ptrdiff_t *) = (ptrdiff_t)size;
        return true;
    }
    return false;
}

static void set_n_value(spec_t *spec, va_list args, size_t size)
{
    if (set_n_short(spec, args, size))
        return;
    if (set_n_long(spec, args, size))
        return;
    if (set_n_special(spec, args, size))
        return;
    *va_arg(args, int *) = (int)size;
}

static result_string_t string_handler(va_list args)
{
    char *str = va_arg(args, char *);

    if (!str)
        return ok_string("(null)");
    return ok_string(str);
}

result_string_t default_case_handler(spec_t *spec, va_list args, size_t size)
{
    return ok_string(length_handler(spec, args, size));
}

result_string_t get_specifier_content(spec_t *spec, va_list args, size_t size)
{
    if (spec->specifier == '%')
        return ok_string("%");
    if (spec->specifier == 's')
        return string_handler(args);
    if (spec->specifier == 'c')
        return char_handler((char)va_arg(args, int));
    if (spec->specifier == 'n') {
        set_n_value(spec, args, size);
        return ok_string("");
    }
    if (spec->specifier == 'p')
        return pointer_handler(va_arg(args, void *));
    return default_case_handler(spec, args, size);
}
