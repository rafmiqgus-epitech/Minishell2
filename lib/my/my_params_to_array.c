/*
** EPITECH PROJECT, 2025
** my_params_to_array.c
** File description:
** stores the program's parameters into an array of structures and
** returns the address
*/

#include "my.h"
#include <stdlib.h>

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param *res = malloc((ac + 1) * sizeof(struct info_param));
    struct info_param student;
    int i;

    for (i = 0; i < ac; i++) {
        student.length = my_strlen(av[i]);
        student.str = av[i];
        student.copy = my_strdup(av[i]);
        student.word_array = my_str_to_word_array(student.str);
        res[i] = student;
    }
    student.length = 0;
    student.str = 0;
    student.copy = 0;
    student.word_array = NULL;
    res[i] = student;
    return res;
}
