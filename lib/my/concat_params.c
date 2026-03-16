/*
** EPITECH PROJECT, 2025
** concat_params.c
** File description:
** concat_params
*/

#include "my.h"
#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    int i = 0;
    int total_size = 0;
    char *res;

    for (int i = 0; i < argc; i++) {
        total_size += (my_strlen(argv[i]) + 1);
    }
    res = malloc(total_size * sizeof(char));
    for (i = 0; i < argc - 1; i++) {
        my_strcat(res, argv[i]);
        my_strcat(res, "\n");
    }
    my_strcat(res, argv[i]);
    return res;
}
