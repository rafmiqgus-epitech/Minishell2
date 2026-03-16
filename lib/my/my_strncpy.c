/*
** EPITECH PROJECT, 2025
** my_strncpy.c
** File description:
** task02
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    return dest;
}
