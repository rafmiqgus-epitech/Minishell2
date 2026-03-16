/*
** EPITECH PROJECT, 2025
** my_strupcase.c
** File description:
** task08
*/

char *my_strupcase(char *str)
{
    char *str_addr = str;

    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 32;
        }
        str++;
    }
    return str_addr;
}
