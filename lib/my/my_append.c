/*
** EPITECH PROJECT, 2025
** my_append.c
** File description:
** appends a string to the end of a null-terminated array of strings
*/

#include "result_pattern_design.h"
#include "my.h"
#include <stdlib.h>

static void fill_array(char **dest, char **src, size_t len)
{
    for (size_t i = 0; i < len; i++)
        dest[i] = src[i];
}

result_string_array_t my_append(char ***array, const char *str)
{
    size_t len = 0;
    char **new_array = NULL;

    if (!array || !str)
        return err_string_array("Null pointer provided to my_append");
    while ((*array)[len])
        len++;
    new_array = malloc(sizeof(char *) * (len + 2));
    if (!new_array)
        return err_string_array("Memory allocation failed in my_append");
    fill_array(new_array, *array, len);
    new_array[len] = my_strdup(str);
    if (!new_array[len]) {
        free(new_array);
        return err_string_array("Memory allocation failed in my_append");
    }
    new_array[len + 1] = NULL;
    free(*array);
    *array = new_array;
    return ok_string_array(new_array);
}
