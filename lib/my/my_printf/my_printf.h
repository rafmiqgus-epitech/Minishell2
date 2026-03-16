/*
** EPITECH PROJECT, 2025
** my_printf.h
** File description:
** Header file for my_printf function
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <stdarg.h>
    #include <stdbool.h>
    #include "../result_pattern_design.h"

typedef struct flags {
    bool hash;
    bool zero;
    bool minus;
    bool plus;
    bool space;
} flags_t;

typedef struct spec {
    flags_t flags;
    int width;
    int precision;
    char length[3];
    char specifier;
    int raw_size;
} spec_t;

struct spec_metrics {
    size_t content_size;
    size_t spec_size;
};

int my_printf(const char *format, ...);
result_size_t get_output_size(const char *format, va_list args);
spec_t spec_parser(const char *format, va_list args);
int fill_buffer(char *output, const char *format,
    va_list args, size_t output_size);
size_t get_content_size(spec_t *spec, va_list args);
char *length_handler(spec_t *spec, va_list args, size_t size);
const char *get_flags(const char *format, spec_t *spec);
const char *get_width(const char *format, spec_t *spec, va_list args);
const char *get_precision(const char *format, spec_t *spec, va_list args);
const char *get_length(const char *format, spec_t *spec);
void get_specifier(const char *format, spec_t *spec);
size_t get_spec_size(spec_t *spec);
result_string_t get_specifier_content(spec_t *spec,
    va_list args, size_t size);
result_string_t get_spec_content(spec_t *spec, va_list args, size_t size);
result_string_t apply_precision(char *content, spec_t *spec);
result_string_t apply_formatting(char *content, spec_t *spec);
char *default_length_handler(spec_t *spec, va_list args, size_t size);
char *safe_return(char *str);
char *utoa_base(unsigned long long nb, const char *base);
char *signed_to_str(long long nb);
char *length_handler(spec_t *spec, va_list args, size_t size);
char *h_length_handler(spec_t *spec, va_list args, size_t size);
char *hh_length_handler(spec_t *spec, va_list args, size_t size);
char *l_length_handler(spec_t *spec, va_list args, size_t size);
char *ll_length_handler(spec_t *spec, va_list args, size_t size);
char *l_maj_length_handler(spec_t *spec, va_list args, size_t size);
char *z_length_handler(spec_t *spec, va_list args, size_t size);
char *j_length_handler(spec_t *spec, va_list args, size_t size);
char *format_float_spec(spec_t *spec, long double value);
char *float_to_fixed(long double value, int precision, bool upper, bool hash);
char *float_to_sci(long double value, int precision, bool upper, bool hash);
char *float_to_general(long double value, int precision,
    bool upper, bool hash);
char *float_to_hex(long double value, int precision, bool upper, bool hash);
int float_class(long double value);
bool float_is_negative(long double value);
long double float_abs(long double value);
long double float_pow10(int precision);
char *float_special_string(long double value, bool upper);

#endif /* MY_PRINTF_H_ */
