/*
** EPITECH PROJECT, 2026
** parse_free.c
** File description:
** free functions for parser structures
*/

#include <stdlib.h>

#include "parser.h"

void free_tokens(token_t *tokens)
{
    token_t *next = NULL;

    for (token_t *current = tokens; current != NULL; current = next) {
        next = current->next;
        free(current->value);
        free(current);
    }
}

void free_command_groups(command_group_t *groups)
{
    command_group_t *next_grp = NULL;
    command_t *next_cmd = NULL;

    for (command_group_t *grp = groups; grp != NULL; grp = next_grp) {
        next_grp = grp->next;
        for (command_t *cmd = grp->pipeline; cmd != NULL; cmd = next_cmd) {
            next_cmd = cmd->next;
            free(cmd->argv);
            free(cmd);
        }
        free(grp);
    }
}
