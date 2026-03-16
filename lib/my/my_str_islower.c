/*
** EPITECH PROJECT, 2025
** my_str_isalpha.c
** File description:
** my_str_isalpha.c
*/

int my_str_islower(char const *str)
{
    while (*str != '\0') {
        if (*str < 'a' || *str > 'z') {
            return 0;
        }
        str++;
    }
    return 1;
}
