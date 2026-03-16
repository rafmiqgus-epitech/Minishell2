/*
** EPITECH PROJECT, 2025
** my_str_to_word_array.c
** File description:
** compatibility wrappers
*/

#include "my.h"

char **my_str_to_word_array_with_delimiters(char const *str,
    char const *delimiters)
{
    return my_split_words(str, delimiters);
}

char **my_str_to_word_array(char const *str)
{
    return my_split_words(str, NULL);
}
