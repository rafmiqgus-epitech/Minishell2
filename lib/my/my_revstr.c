/*
** EPITECH PROJECT, 2025
** my_revstr.c
** File description:
** task03
*/

#include "my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int middle = len / 2;
    int index = 0;
    char temp;
    char temp2;

    while (index != middle) {
        temp = str[index];
        temp2 = str[(len - 1) - index];
        str[index] = temp2;
        str[(len - 1) - index] = temp;
        index += 1;
    }
    return str;
}
