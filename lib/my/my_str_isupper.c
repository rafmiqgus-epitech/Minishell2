/*
** EPITECH PROJECT, 2025
** my_str_isalpha.c
** File description:
** my_str_isalpha.c
*/

int my_str_isupper(char const *str)
{
    while (*str != '\0') {
        if (*str < 'A' || *str > 'Z') {
            return 0;
        }
        str++;
    }
    return 1;
}
