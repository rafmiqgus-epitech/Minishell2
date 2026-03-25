/*
** EPITECH PROJECT, 2026
** env.c
** File description:
** env replica
*/

#include "builtins.h"
#include "mysh.h"
#include "my.h"

int my_env(shell_t *shell, __attribute__((unused)) char **argv)
{
    for (size_t i = 0; shell->env[i]; ++i) {
        my_printf("%s\n", shell->env[i]);
    }
    return SUCCESS_EXIT;
}
