/*
** EPITECH PROJECT, 2026
** env.c
** File description:
** env replica
*/

#include "../../include/builtins.h"
#include "../../include/mysh.h"
#include "../../include/my.h"

int my_env(shell_t *shell, __attribute__((unused)) char **argv)
{
    for (size_t i = 0; shell->env[i]; ++i) {
        my_printf("%s\n", shell->env[i]);
    }
    return SUCCESS_EXIT;
}
