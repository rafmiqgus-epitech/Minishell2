/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** apply width and flags on prepared spec content
*/

#include "../my_printf.h"
#include "../../my.h"
#include <stdlib.h>

struct numeric_parts {
    bool neg;
    const char *digits;
    char sign;
    const char *prefix;
    int prefix_len;
    int core_len;
    int pad;
    char pad_c;
};

static bool is_zero_string(const char *str)
{
    int i = 0;

    if (!str || str[0] == '\0')
        return true;
    while (str[i]) {
        if (str[i] != '0')
            return false;
        i = i + 1;
    }
    return true;
}

static char get_sign(const spec_t *spec, bool neg)
{
    if (!is_in_char(spec->specifier, "difFeEgGaA"))
        return '\0';
    if (neg)
        return '-';
    if (spec->flags.plus)
        return '+';
    if (spec->flags.space)
        return ' ';
    return '\0';
}

static const char *get_prefix(const spec_t *spec, const char *digits, int *len)
{
    if (spec->specifier == 'p') {
        *len = 2;
        return "0x";
    }
    if (is_in_char(spec->specifier, "xX")
        && spec->flags.hash && !is_zero_string(digits)) {
        *len = 2;
        return (spec->specifier == 'x') ? "0x" : "0X";
    }
    if (spec->specifier == 'o' && spec->flags.hash
        && (digits[0] == '\0' || digits[0] != '0')) {
        *len = 1;
        return "0";
    }
    *len = 0;
    return "";
}

static int append_char_n(char *dst, int idx, char c, int count)
{
    int i = 0;

    while (i < count) {
        dst[idx] = c;
        idx = idx + 1;
        i = i + 1;
    }
    return idx;
}

static int append_str(char *dst, int idx, const char *str, int len)
{
    int i = 0;

    while (i < len) {
        dst[idx] = str[i];
        idx = idx + 1;
        i = i + 1;
    }
    return idx;
}

static void get_numeric_parts(char *content, spec_t *spec,
    struct numeric_parts *parts)
{
    *parts = (struct numeric_parts){false, content, '\0', "", 0, 0, 0, ' '};
    parts->neg = (content[0] == '-');
    parts->digits = content + (parts->neg ? 1 : 0);
    if (is_in_char(spec->specifier, "aA") && parts->digits[0] == '0'
        && is_in_char(parts->digits[1], "xX")) {
        parts->prefix = (spec->specifier == 'A') ? "0X" : "0x";
        parts->prefix_len = 2;
        parts->digits = parts->digits + 2;
    }
    parts->sign = get_sign(spec, parts->neg);
    if (parts->prefix_len == 0)
        parts->prefix = get_prefix(spec, parts->digits, &parts->prefix_len);
    parts->core_len = my_strlen(parts->digits) + parts->prefix_len;
    if (parts->sign != '\0')
        parts->core_len = parts->core_len + 1;
    if (spec->width > parts->core_len)
        parts->pad = spec->width - parts->core_len;
    if (spec->flags.zero && !spec->flags.minus
        && (spec->precision < 0 || is_in_char(spec->specifier, "fFeEgGaA")))
        parts->pad_c = '0';
}

static char *build_numeric_content(spec_t *spec, struct numeric_parts *parts)
{
    char *res = malloc(parts->core_len + parts->pad + 1);
    int idx = 0;

    if (!res)
        return NULL;
    if (!spec->flags.minus && parts->pad_c == ' ')
        idx = append_char_n(res, idx, ' ', parts->pad);
    if (parts->sign != '\0')
        idx = append_char_n(res, idx, parts->sign, 1);
    idx = append_str(res, idx, parts->prefix, parts->prefix_len);
    if (!spec->flags.minus && parts->pad_c == '0')
        idx = append_char_n(res, idx, '0', parts->pad);
    idx = append_str(res, idx, parts->digits, my_strlen(parts->digits));
    if (spec->flags.minus)
        idx = append_char_n(res, idx, ' ', parts->pad);
    res[idx] = '\0';
    return res;
}

static char *format_numeric_content(char *content, spec_t *spec)
{
    struct numeric_parts parts;

    get_numeric_parts(content, spec, &parts);
    if (parts.pad == 0 && parts.prefix_len == 0
        && parts.sign != '+' && parts.sign != ' ')
        return content;
    return build_numeric_content(spec, &parts);
}

static char *format_text_content(char *content, spec_t *spec)
{
    int len = my_strlen(content);
    int pad = (spec->width > len) ? spec->width - len : 0;
    char pad_c = ' ';
    char *res = NULL;
    int idx = 0;

    if (spec->specifier == '%' && spec->flags.zero && !spec->flags.minus)
        pad_c = '0';
    if (pad == 0)
        return content;
    res = malloc(spec->width + 1);
    if (!res)
        return NULL;
    if (!spec->flags.minus)
        idx = append_char_n(res, idx, pad_c, pad);
    idx = append_str(res, idx, content, len);
    if (spec->flags.minus)
        idx = append_char_n(res, idx, ' ', pad);
    res[idx] = '\0';
    return res;
}

result_string_t apply_formatting(char *content, spec_t *spec)
{
    char *formatted = content;

    if (!content)
        return ok_string(NULL);
    if (is_in_char(spec->specifier, "diouxXpfFeEgGaA"))
        formatted = format_numeric_content(content, spec);
    if (is_in_char(spec->specifier, "sc%"))
        formatted = format_text_content(content, spec);
    if (!formatted)
        return err_string("Formatting failed");
    return ok_string(formatted);
}
