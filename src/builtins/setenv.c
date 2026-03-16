/*
** EPITECH PROJECT, 2026
** setenv.c
** File description:
** setenv replica
*/

#include "../../include/builtins.h"
#include "../../include/mysh.h"
#include "../../include/env.h"
#include "../../include/my.h"

#include <stdlib.h>

int my_setenv(shell_t *shell, char **argv)
{
    size_t arg_nb = string_array_len(argv);

    if (arg_nb > 3) {
        (void)write(2, "setenv: Too much arguments.\n", 31);
        return FAILURE_EXIT;
    }
    if (arg_nb == 1) {
        my_env(shell, argv);
        return SUCCESS_EXIT;
    }
    if (!valid_env_key(argv[1])) {
        print_error("setenv:");
        print_error(" Variable name must contain alphanumeric characters.\n");
        return SUCCESS_EXIT;
    }
    if (env_set_value(shell, argv[1], argv[2]) != SUCCESS_EXIT)
        return FAILURE_EXIT;
    return SUCCESS_EXIT;
}
