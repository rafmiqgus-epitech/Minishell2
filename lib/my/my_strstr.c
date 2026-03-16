/*
** EPITECH PROJECT, 2025
** my_strstr.c
** File description:
** task05
*/

#include <stdlib.h>

static int found_instance(char *str, char const *to_find)
{
    char const *to_find_temp = to_find;

    while (*to_find_temp != '\0') {
        if (*str != *to_find_temp) {
            return 0;
        }
        to_find_temp++;
        str++;
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    int found = 0;

    while (*str != '\0') {
        if (*str == *to_find) {
            found = found_instance(str, to_find);
        }
        if (found) {
            return str;
        }
        str++;
    }
    return NULL;
}
