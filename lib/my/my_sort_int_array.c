/*
** EPITECH PROJECT, 2025
** my_sort_int_array.c
** File description:
** task06
*/

static void swap(int *a, int *b)
{
    int temp = *b;

    *b = *a;
    *a = temp;
}

static void detect_swap(int *array, int nb_swap)
{
    if (*array > *(array + 1)) {
        swap(array, array + 1);
        nb_swap++;
    }
}

void my_sort_int_array(int *array, int size)
{
    int nb_swap = 1;
    int temp;
    int *nb_swap_addr = array;

    if (size == 0) {
        return;
    }
    while (nb_swap > 0) {
        nb_swap = 0;
        array = nb_swap_addr;
        for (int i = 0; i < size - 1; i++) {
            detect_swap(array, nb_swap);
            array++;
        }
    }
}
