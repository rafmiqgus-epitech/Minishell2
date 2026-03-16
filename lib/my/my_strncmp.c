/*
** EPITECH PROJECT, 2025
** my_strncmp.c
** File description:
** task07
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (*s1 != '\0' && *s2 != '\0') {
        if (i == n) {
            break;
        }
        if (*s1 != *s2) {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return 0;
}
