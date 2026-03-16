/*
** EPITECH PROJECT, 2025
** result_pattern_design.h
** File description:
** Result pattern helpers without multiline macros
*/

#ifndef RESULT_PATTERN_DESIGN_H_
    #define RESULT_PATTERN_DESIGN_H_

    #include <stdbool.h>
    #include <stddef.h>

typedef struct {
    bool ok;
    union {
        int value;
        const char *error_msg;
    } data;
} result_int_t;

result_int_t ok_int(int val);

result_int_t err_int(const char *msg);

typedef struct {
    bool ok;
    union {
        size_t size;
        const char *error_msg;
    } data;
} result_size_t;

result_size_t ok_size(size_t val);

result_size_t err_size(const char *msg);

typedef struct {
    bool ok;
    union {
        char c;
        const char *error_msg;
    } data;
} result_char_t;

result_char_t ok_char(char val);

result_char_t err_char(const char *msg);

typedef struct {
    bool ok;
    union {
        char *string;
        const char *error_msg;
    } data;
} result_string_t;

result_string_t ok_string(char *val);

result_string_t err_string(const char *msg);

typedef struct {
    bool ok;
    union {
        char **array;
        const char *error_msg;
    } data;
} result_string_array_t;

result_string_array_t ok_string_array(char **val);

result_string_array_t err_string_array(const char *msg);

    #define IS_OK(result) ((result).ok)
    #define IS_ERROR(result) (!(result).ok)
    #define GET_ERROR(result) ((result).data.error_msg)

#endif /* !RESULT_PATTERN_DESIGN_H_ */
