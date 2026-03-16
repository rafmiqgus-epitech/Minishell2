/*
** EPITECH PROJECT, 2026
** my_char_isalpha.c
** File description:
** returns true is given character is an alphanumerical character, else returns
** false
*/

#include <stdbool.h>

bool my_char_isalpha(char c)
{
    if ((c < 'a' && c > 'z') || (c < 'A' || c > 'Z'))
        return false;
    return true;
}
