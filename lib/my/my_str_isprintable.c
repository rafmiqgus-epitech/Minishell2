/*
** EPITECH PROJECT, 2025
** my_str_isalpha.c
** File description:
** my_str_isalpha.c
*/

int my_str_isprintable(char const *str)
{
    while (*str != '\0') {
        if (*str < 33 || *str > 127) {
            return 0;
        }
        str++;
    }
    return 1;
}
