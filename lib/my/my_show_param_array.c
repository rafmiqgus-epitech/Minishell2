/*
** EPITECH PROJECT, 2025
** my_show_param_array.c
** File description:
** displays the content of an array created with my_params_to_array.c
*/

#include "my.h"
#include <stdlib.h>

int my_show_param_array(const struct info_param *par)
{
    for (int i = 0; par[i].str != NULL; i++) {
        my_putstr(par[i].str);
        my_putchar('\n');
        my_put_nbr(par[i].length);
        my_putchar('\n');
        my_show_word_array(par[i].word_array);
        my_putchar('\n');
    }
    return 0;
}
