/*
** EPITECH PROJECT, 2026
** init.c
** File description:
** initialize shell state
*/

#include "../../include/shell.h"
#include "../../include/mysh.h"
#include "../../include/my.h"

#include <stdbool.h>
#include <unistd.h>

bool shell_init(shell_t *shell, char **envp)
{
    shell->env = dup_string_array(envp);
    if (shell->env == NULL)
        return false;
    shell->last_status = SUCCESS_EXIT;
    shell->line = NULL;
    shell->last_pid = -1;
    return true;
}
