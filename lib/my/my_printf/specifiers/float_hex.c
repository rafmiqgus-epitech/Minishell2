/*
** EPITECH PROJECT, 2025
** float_hex.c
** File description:
** hexadecimal float formatter
*/

#include "../my_printf.h"
#include "../../my.h"
#include <stdlib.h>

struct hex_ctx {
    long double norm;
    int exp;
    int precision;
    bool dot;
};

static void normalize_bin(long double *norm, int *exp)
{
    while (*norm >= 2.0L) {
        *norm = *norm / 2.0L;
        *exp = *exp + 1;
    }
    while (*norm > 0.0L && *norm < 1.0L) {
        *norm = *norm * 2.0L;
        *exp = *exp - 1;
    }
}

static long double pow16_ld(int precision)
{
    long double scale = 1.0L;
    int i = 0;

    for (i = 0; i < precision; i++)
        scale = scale * 16.0L;
    return scale;
}

static char *build_frac_hex(long double frac, int precision, bool upper)
{
    const char *digits = upper ? "0123456789ABCDEF" : "0123456789abcdef";
    char *result = malloc(precision + 1);
    int i = 0;
    int digit = 0;

    if (!result)
        return NULL;
    for (i = 0; i < precision; i++) {
        frac = frac * 16.0L;
        digit = (int)frac;
        frac = frac - (long double)digit;
        result[i] = digits[digit];
    }
    result[precision] = '\0';
    return result;
}

static char *build_exp_part(int exp)
{
    char *digits = my_int_to_base((exp < 0) ? -exp : exp, "0123456789");
    int len = 0;
    char *result = NULL;

    if (!digits)
        return NULL;
    len = my_strlen(digits);
    result = malloc(len + 2);
    if (!result)
        return NULL;
    result[0] = (exp < 0) ? '-' : '+';
    my_strcpy(result + 1, digits);
    free(digits);
    return result;
}

static char *build_hex_core(bool upper, bool dot, char lead, char *frac)
{
    int len_f = my_strlen(frac);
    int len = 3 + (dot ? 1 : 0) + len_f + 2;
    char *core = malloc(len);

    if (!core)
        return NULL;
    core[0] = '0';
    core[1] = upper ? 'X' : 'x';
    core[2] = lead;
    if (!dot)
        core[3] = '\0';
    if (dot) {
        core[3] = '.';
        my_strcpy(core + 4, frac);
    }
    return core;
}

static char *append_exp(char *core, bool upper, char *exp_part)
{
    int len_c = my_strlen(core);
    int len_e = my_strlen(exp_part);
    char *result = malloc(len_c + 1 + len_e + 1);

    if (!result)
        return NULL;
    my_strcpy(result, core);
    result[len_c] = upper ? 'P' : 'p';
    my_strcpy(result + len_c + 1, exp_part);
    return result;
}

static char *add_sign(char *str, bool neg)
{
    char *result = NULL;

    if (!str)
        return NULL;
    if (!neg)
        return str;
    result = malloc(my_strlen(str) + 2);
    if (!result)
        return NULL;
    result[0] = '-';
    my_strcpy(result + 1, str);
    free(str);
    return result;
}

static void prepare_hex_ctx(struct hex_ctx *ctx,
    long double value, int precision, bool hash)
{
    ctx->norm = float_abs(value);
    ctx->exp = 0;
    ctx->precision = precision;
    ctx->dot = (precision > 0 || hash);
    if (ctx->norm != 0.0L)
        normalize_bin(&ctx->norm, &ctx->exp);
    ctx->norm = ctx->norm + (0.5L / pow16_ld(precision));
    if (ctx->norm >= 2.0L && precision > 0) {
        ctx->norm = ctx->norm / 2.0L;
        ctx->exp = ctx->exp + 1;
    }
}

static char *build_hex_output(struct hex_ctx *ctx, bool upper)
{
    const char *digits = upper ? "0123456789ABCDEF" : "0123456789abcdef";
    int lead = 0;
    char *frac = NULL;
    char *exp_part = NULL;
    char *core = NULL;
    char *result = NULL;

    lead = (int)ctx->norm;
    if (ctx->norm == 0.0L)
        lead = 0;
    frac = build_frac_hex(ctx->norm - (long double)lead, ctx->precision, upper);
    exp_part = build_exp_part(ctx->exp);
    core = build_hex_core(upper, ctx->dot, digits[lead], frac);
    if (!frac || !exp_part || !core)
        return NULL;
    result = append_exp(core, upper, exp_part);
    free(frac);
    free(exp_part);
    free(core);
    return result;
}

char *float_to_hex(long double value, int precision, bool upper, bool hash)
{
    struct hex_ctx ctx = {0.0L, 0, precision, false};
    char *result = NULL;

    if (precision < 0) {
        if (value == 0.0L)
            ctx.precision = 0;
        else
            ctx.precision = 13;
    }
    if (float_class(value) != 0)
        return float_special_string(value, upper);
    prepare_hex_ctx(&ctx, value, ctx.precision, hash);
    result = build_hex_output(&ctx, upper);
    return add_sign(result, float_is_negative(value));
}
