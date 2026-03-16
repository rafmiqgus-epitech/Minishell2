/*
** EPITECH PROJECT, 2026
** run_command.c
** File description:
** decide builtin vs external
*/

#include "../../include/my.h"
#include "../../include/builtins.h"
#include "../../include/shell.h"
#include "../../include/exec.h"

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

enum shell_status run_command(shell_t *shell, char *input_buf)
{
    char **argv = my_split_words(input_buf, " \t\n");
    bool should_exit = false;

    if (argv == NULL) {
        perror("malloc(my_str_to_word_array)");
    }
    if (run_builtin(shell, argv, &should_exit)) {
        if (should_exit) {
            free_string_array(argv);
            return SHELL_EXIT;
        }
    } else {
        run_external(shell, argv);
    }
    free_string_array(argv);
    return SHELL_CONTINUE;
}
