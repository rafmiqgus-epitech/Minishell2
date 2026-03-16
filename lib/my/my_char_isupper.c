/*
** EPITECH PROJECT, 2025
** my_isupper_char.c
** File description:
** Checks is char is uppercase
*/

int my_char_isupper(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    return 0;
}
