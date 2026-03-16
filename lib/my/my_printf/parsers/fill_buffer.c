/*
** EPITECH PROJECT, 2025
** fill_buffer.c
** File description:
** fills the ouputted buffer
*/

#include <stddef.h>
#include <stdarg.h>
#include "../../my.h"
#include "../my_printf.h"
#include "../../result_pattern_design.h"

struct write_idx {
    size_t *fmt_idx;
    size_t *out_idx;
};

static result_string_t spec_handler(const char *format, size_t *size,
    va_list args, size_t *i)
{
    spec_t spec = spec_parser(&format[*i + 1], args);
    result_string_t spec_content;

    if (!spec.specifier)
        return ok_string(NULL);
    spec_content = get_spec_content(&spec, args, *size);
    if (spec_content.ok == false)
        return err_string("Something went wrong while getting spec content");
    *i += get_spec_size(&spec);
    return spec_content;
}

static size_t append_string(char *output, size_t out_idx, const char *str)
{
    size_t i = 0;

    while (str[i]) {
        output[out_idx] = str[i];
        out_idx = out_idx + 1;
        i = i + 1;
    }
    return out_idx;
}

static int write_spec(char *output, const char *format, va_list args,
    struct write_idx *idx)
{
    result_string_t spec_content;

    spec_content = spec_handler(format, idx->out_idx, args, idx->fmt_idx);
    if (spec_content.ok == false) {
        print_error("Something went wrong while filling the buffer\n");
        return 84;
    }
    if (spec_content.data.string == NULL) {
        output[*idx->out_idx] = format[*idx->fmt_idx];
        *idx->out_idx = *idx->out_idx + 1;
        return 0;
    }
    *idx->out_idx = append_string(output, *idx->out_idx,
        spec_content.data.string);
    return 0;
}

int fill_buffer(char *output, const char *format, va_list args, size_t size)
{
    size_t out_idx = 0;
    int status = 0;
    struct write_idx idx = {NULL, NULL};

    for (size_t i = 0; format[i]; i++) {
        idx.fmt_idx = &i;
        idx.out_idx = &out_idx;
        if (format[i] != '%') {
            output[out_idx] = format[i];
            out_idx = out_idx + 1;
            continue;
        }
        status = write_spec(output, format, args, &idx);
        if (status == 84)
            return 84;
    }
    output[size] = '\0';
    return 0;
}
