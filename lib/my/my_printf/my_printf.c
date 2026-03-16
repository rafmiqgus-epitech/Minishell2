/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** replica of libc printf
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_printf.h"
#include "../result_pattern_design.h"

static int free_all(char *output, va_list args, va_list args_tmp)
{
    va_end(args);
    va_end(args_tmp);
    free(output);
    return -1;
}

int my_printf(const char *format, ...)
{
    va_list args;
    va_list args_tmp;
    char *output;
    result_size_t output_size;

    va_start(args, format);
    va_start(args_tmp, format);
    output_size = get_output_size(format, args_tmp);
    if (output_size.ok == false)
        return free_all(NULL, args, args_tmp);
    output = malloc(output_size.data.size + 1);
    if (!output)
        return free_all(output, args, args_tmp);
    output[0] = '\0';
    fill_buffer(output, format, args, output_size.data.size);
    (void)write(1, output, output_size.data.size);
    free_all(output, args, args_tmp);
    return output_size.data.size;
}
