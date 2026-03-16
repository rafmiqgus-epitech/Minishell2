/*
** EPITECH PROJECT, 2025
** my_strcapitalize.c
** File description:
** task10
*/

static void found_lower_case(char *str, int index)
{
    if (str[index - 1] == ' ' ||
        str[index - 1] == '-' ||
        str[index - 1] == '+') {
        str[index] -= 32;
    }
}

static void found_upper_case(char *str, int index)
{
    if (str[index - 1] != ' ' &&
        str[index - 1] != '-' &&
        str[index - 1] != '+') {
        str[index] += 32;
    }
}

char *my_strcapitalize(char *str)
{
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] -= 32;
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            found_lower_case(str, i);
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
            found_upper_case(str, i);
        }
    }
    return str;
}
