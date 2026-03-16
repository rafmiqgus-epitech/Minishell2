/*
** EPITECH PROJECT, 2026
** loop.c
** File description:
** prompt/read/parse/execute loop
*/

#include "../../include/mysh.h"
#include "../../include/my.h"
#include "../../include/exec.h"
#include "../../include/shell.h"

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int shell_loop(shell_t *shell)
{
    size_t cap = 0;
    ssize_t nread;
    enum shell_status status = SHELL_CONTINUE;
    bool is_interactive = isatty(STDIN_FILENO);

    while (status == SHELL_CONTINUE) {
        if (is_interactive)
            my_printf("%s", SUCCESS_PROMPT);
        nread = getline(&shell->line, &cap, stdin);
        if (nread == -1)
            break;
        status = run_command(shell, shell->line);
    }
    return shell->last_status;
}
