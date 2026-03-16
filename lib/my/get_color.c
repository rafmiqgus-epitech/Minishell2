/*
** EPITECH PROJECT, 2025
** get_color.c
** File description:
** returns the color as an int by handling its three RGB components
*/

#include "my.h"

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int res = red;

    res <<= 8;
    res += green;
    res <<= 8;
    res += blue;
    return res;
}
