/*
** EPITECH PROJECT, 2025
** my_memset.c
** File description:
** fills an allocated space in memory
*/

void *my_memset(void *s, int c, unsigned int n)
{
    unsigned int i;
    unsigned char *ptr = (unsigned char *)s;

    for (i = 0; i < n; i++) {
        ptr[i] = (unsigned char)c;
    }
    return s;
}
