/*
** EPITECH PROJECT, 2025
** my_strcpy.c
** File description:
** task01
*/

char *my_strcpy(char *dest, char const *src)
{
    char *dest_addr = dest;

    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return dest_addr;
}
