/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** contains the function necessary to get the final size of the format
*/

#include "../../my.h"
#include "../my_printf.h"
#include "../../result_pattern_design.h"

static result_size_t spec_handler(const char *format, size_t *size,
    va_list args, size_t *i)
{
    struct spec_metrics spec_sizes = {0, 0};
    spec_t spec = spec_parser(&format[*i + 1], args);
    result_string_t spec_content;

    if (!spec.specifier)
        return ok_size(0);
    spec_content = get_spec_content(&spec, args, *size);
    if (spec_content.ok == false)
        return err_size("Something went wrong while getting spec content");
    spec_sizes.content_size = my_strlen(spec_content.data.string);
    spec_sizes.spec_size = get_spec_size(&spec);
    *i += spec_sizes.spec_size;
    return ok_size(spec_sizes.content_size);
}

static result_size_t update_size_from_spec(const char *format, size_t *size,
    va_list args, size_t *i)
{
    result_size_t size_tmp = ok_size(0);
    size_t prev_i = *i;

    size_tmp = spec_handler(format, size, args, i);
    if (size_tmp.ok == false)
        return err_size("Something went wrong while getting spec content");
    if (size_tmp.data.size == 0 && *i == prev_i) {
        *size = *size + 1;
        return ok_size(0);
    }
    *size = *size + size_tmp.data.size;
    return ok_size(0);
}

result_size_t get_output_size(const char *format, va_list args)
{
    result_size_t size = ok_size(0);
    result_size_t step = ok_size(0);

    if (my_strlen(format) == 0)
        return ok_size(0);
    for (size_t i = 0; format[i]; i++) {
        if (format[i] != '%') {
            size.data.size = size.data.size + 1;
            continue;
        }
        step = update_size_from_spec(format, &size.data.size, args, &i);
        if (step.ok == false)
            return step;
    }
    return size;
}
