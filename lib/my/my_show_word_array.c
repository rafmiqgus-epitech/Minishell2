/*
** EPITECH PROJECT, 2025
** my_show_word_array.c
** File description:
** displays the content of an array of words
*/

#include "my.h"

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}
