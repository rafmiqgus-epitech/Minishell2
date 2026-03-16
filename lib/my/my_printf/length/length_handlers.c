/*
** EPITECH PROJECT, 2025
** length_handler.c
** File description:
** main length handler dispatcher
*/

#include "../../my.h"
#include "../my_printf.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>


char *safe_return(char *str)
{
    if (!str)
        return NULL;
    return str;
}

char *utoa_base(unsigned long long nb, const char *base)
{
    return my_int_to_base(nb, base);
}

char *signed_to_str(long long nb)
{
    char *str = NULL;
    char *res = NULL;

    if (nb >= 0)
        return my_int_to_base((unsigned long long)nb, "0123456789");
    str = my_int_to_base((unsigned long long)(-nb), "0123456789");
    if (!str)
        return NULL;
    res = malloc(my_strlen(str) + 2);
    if (!res) {
        free(str);
        return NULL;
    }
    res[0] = '-';
    my_strcpy(res + 1, str);
    free(str);
    return res;
}

char *length_handler(spec_t *spec, va_list args, size_t size)
{
    if (spec->length[0] == '\0')
        return default_length_handler(spec, args, size);
    if (my_strcmp(spec->length, "hh") == 0)
        return hh_length_handler(spec, args, size);
    if (my_strcmp(spec->length, "h") == 0)
        return h_length_handler(spec, args, size);
    if (my_strcmp(spec->length, "l") == 0)
        return l_length_handler(spec, args, size);
    if (my_strcmp(spec->length, "ll") == 0)
        return ll_length_handler(spec, args, size);
    if (my_strcmp(spec->length, "j") == 0)
        return j_length_handler(spec, args, size);
    if (my_strcmp(spec->length, "z") == 0)
        return z_length_handler(spec, args, size);
    if (my_strcmp(spec->length, "L") == 0)
        return l_maj_length_handler(spec, args, size);
    return NULL;
}
