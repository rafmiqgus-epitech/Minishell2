/*
** EPITECH PROJECT, 2025
** random_utils.c
** File description:
** random generators
*/

#include <stdlib.h>
#include <stdbool.h>

int rand_int(int min, int max)
{
    return min + rand() % (max - min + 1);
}

float rand_float(float min, float max)
{
    float range = max - min;

    if (range <= 0.0f)
        return min;
    return min + ((float)rand() / (float)RAND_MAX) * range;
}

bool rand_bool(void)
{
    return (rand() % 2) != 0;
}
