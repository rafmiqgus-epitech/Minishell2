/*
** EPITECH PROJECT, 2025
** my_strlowcase.c
** File description:
** task09
*/

char *my_strlowcase(char *str)
{
    char *str_addr = str;

    while (*str != '\0') {
        if (*str >= 'A' && *str <= 'Z') {
            *str += 32;
        }
        str++;
    }
    return str_addr;
}
