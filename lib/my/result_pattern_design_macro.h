/*
** EPITECH PROJECT, 2025
** return_design_pattern.h
** File description:
** header file of result pattern design utils
*/

#ifndef RETURN_PATTERN_DESIGN_H
    #define RETURN_PATTERN_DESIGN_H

#include <stddef.h>
#include <stdbool.h>

#define DEFINE_RESULT_TYPE(TypeName, ValueType, ValueField) \
    typedef struct { \
        bool ok; \
        union { \
            ValueType ValueField; \
            const char *error_msg; \
        } data; \
    } result##TypeName##_t;

#define OK_FUNC(TypeName, ValueType, ValueField) \
    static inline result##TypeName##_t Ok##TypeName(ValueType val) { \
        result##TypeName##_t res = {.ok = true}; \
        res.data.ValueField = val; \
        return res; \
    }

#define ERROR_FUNC(TypeName) \
    static inline result##TypeName##_t Err##TypeName(const char *msg) { \
        result##TypeName##_t res = {.ok = false}; \
        res.data.error_msg = msg; \
        return res; \
    }

#define DEFINE_RESULT(TypeName, ValueType, ValueField) \
    DEFINE_RESULT_TYPE(TypeName, ValueType, ValueField) \
    OK_FUNC(TypeName, ValueType, ValueField) \
    ERROR_FUNC(TypeName)

#define IS_OK(result) ((result).ok)

#define IS_ERROR(result) (!(result).ok)

#define GET_ERROR(result) ((result).data.error_msg)

DEFINE_RESULT(Int, int, value)

DEFINE_RESULT(Size, size_t, size)

DEFINE_RESULT(Char, char, c)

DEFINE_RESULT(String, char *, string)

#endif // RETURN_PATTERN_DESIGN_H
