/*
** EPITECH PROJECT, 2025
** precision_utils.c
** File description:
** file containing the precision related functions
*/

#include "../my_printf.h"
#include "../../result_pattern_design.h"
#include "../../my.h"
#include <stdlib.h>

static result_string_t apply_string_precision(char *content, spec_t *spec)
{
    int len = my_strlen(content);
    char *result = NULL;

    if (len <= spec->precision || spec->precision < 0)
        return ok_string(content);
    result = malloc(sizeof(char) * (spec->precision + 1));
    if (!result)
        return err_string("Something went wrong while applying precision.");
    for (int i = 0; i < spec->precision; i++)
        result[i] = content[i];
    result[spec->precision] = '\0';
    return ok_string(result);
}

static result_string_t larger_precision_numberic_handler(char *content,
    spec_t *spec, size_t len)
{
    bool neg = (content[0] == '-');
    int padding_zeros = spec->precision - len + (neg ? 1 : 0);
    char *result = malloc(sizeof(char) * (spec->precision + (neg ? 2 : 1)));
    int pos = 0;
    int i = 0;

    if (!result)
        return err_string("Something went wrong while applying precision.");
    if (neg) {
        result[pos] = '-';
        pos = pos + 1;
    }
    for (i = 0; i < padding_zeros; i++) {
        result[pos] = '0';
        pos = pos + 1;
    }
    my_strcpy(result + pos, content + (neg ? 1 : 0));
    free(content);
    return ok_string(result);
}

static result_string_t apply_numeric_precision(char *content, spec_t *spec)
{
    int len = my_strlen(content);

    if (spec->precision == 0 && my_strcmp("0", content) == 0)
        return ok_string("");
    if (len < spec->precision) {
        return larger_precision_numberic_handler(content, spec, len);
    } else {
        return ok_string(content);
    }
}

result_string_t apply_precision(char *content, spec_t *spec)
{
    if (spec->specifier == 's')
        return apply_string_precision(content, spec);
    if (is_in_char(spec->specifier, "diouxX"))
        return apply_numeric_precision(content, spec);
    return ok_string(content);
}
