/*
** EPITECH PROJECT, 2026
** builtins.h
** File description:
** builtin dispatch + builtin prototypes
*/

#ifndef BUILTINS_H_
    #define BUILTINS_H_

    #include <stdbool.h>
    #include "exec.h"

typedef int (*builtin_fn_t)(shell_t *shell, char **argv);

typedef struct {
    const char *name;
    builtin_fn_t fn;
} builtin_entry_t;

bool run_builtin(shell_t *shell, char **argv, bool *should_exit);

// builtin prototypes
int shell_exit(shell_t *shell, char **argv);
int my_cd(shell_t *shell, char **argv);
int my_setenv(shell_t *shell, char **argv);
int my_unsetenv(shell_t *shell, char **argv);
int my_env(shell_t *shell, char **argv);

#endif // !BUILTINS_H_
