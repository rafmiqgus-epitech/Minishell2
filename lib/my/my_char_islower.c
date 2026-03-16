/*
** EPITECH PROJECT, 2025
** my_islower_char.c
** File description:
** Checks if char is lowercase
*/

int my_char_islower(char c)
{
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    return 0;
}
