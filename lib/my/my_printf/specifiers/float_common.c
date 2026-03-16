/*
** EPITECH PROJECT, 2025
** float_common.c
** File description:
** shared float helpers
*/

#include "../my_printf.h"
#include "../../my.h"
#include <stdlib.h>
#include <stdint.h>

int float_class(long double value)
{
    long double delta = 0.0L;

    if (value != value)
        return 1;
    delta = value - value;
    if (delta != delta)
        return 2;
    return 0;
}

bool float_is_negative(long double value)
{
    union {
        double value;
        uint64_t bits;
    } sign_bits;

    if (value < 0.0L)
        return true;
    if (value == 0.0L && (1.0L / value) < 0.0L)
        return true;
    sign_bits.value = (double)value;
    return ((sign_bits.bits >> 63) == 1);
}

long double float_abs(long double value)
{
    if (float_is_negative(value))
        return -value;
    return value;
}

long double float_pow10(int precision)
{
    long double scale = 1.0L;
    int i = 0;

    for (i = 0; i < precision; i++)
        scale = scale * 10.0L;
    return scale;
}

static const char *special_word(int cls, bool upper)
{
    if (cls == 1)
        return upper ? "NAN" : "nan";
    if (cls == 2)
        return upper ? "INF" : "inf";
    return NULL;
}

char *float_special_string(long double value, bool upper)
{
    const char *word = special_word(float_class(value), upper);
    int cls = float_class(value);
    bool neg = false;
    char *result = NULL;

    if (!word)
        return NULL;
    neg = ((cls == 1 || cls == 2) && float_is_negative(value));
    result = malloc(my_strlen(word) + (neg ? 2 : 1));
    if (!result)
        return NULL;
    if (!neg)
        my_strcpy(result, word);
    if (neg) {
        result[0] = '-';
        my_strcpy(result + 1, word);
    }
    return result;
}
