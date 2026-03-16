/*
** EPITECH PROJECT, 2026
** cd.c
** File description:
** cd replica
*/

#include "../../include/builtins.h"
#include "../../include/env.h"
#include "../../include/mysh.h"
#include "../../include/my.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

static int sync_pwd_vars(shell_t *shell, const char *oldpwd)
{
    char *newpwd = getcwd(NULL, 0);

    if (env_set_value(shell, "OLDPWD", oldpwd) != SUCCESS_EXIT) {
        free(newpwd);
        return FAILURE_EXIT;
    }
    if (newpwd == NULL)
        return SUCCESS_EXIT;
    if (env_set_value(shell, "PWD", newpwd) != SUCCESS_EXIT) {
        free(newpwd);
        return FAILURE_EXIT;
    }
    free(newpwd);
    return SUCCESS_EXIT;
}

bool is_a_dir(const char *target)
{
    struct stat st;

    if (stat(target, &st) == -1)
        return true;
    if (!S_ISDIR(st.st_mode)) {
        print_error(target);
        print_error(": Not a directory.");
        return false;
    }
    return true;
}

static int handle_chdir_error(const char *target, char *oldpwd)
{
    int err = errno;

    perror(target);
    free(oldpwd);
    if (err == ENOENT)
        return SUCCESS_EXIT;
    return FAILURE_EXIT;
}

static int cd_to(shell_t *shell, const char *target)
{
    char *oldpwd = getcwd(NULL, 0);

    if (oldpwd == NULL)
        return FAILURE_EXIT;
    if (!is_a_dir(target)) {
        free(oldpwd);
        return SUCCESS_EXIT;
    }
    if (chdir(target) == -1)
        return handle_chdir_error(target, oldpwd);
    if (sync_pwd_vars(shell, oldpwd) != SUCCESS_EXIT) {
        free(oldpwd);
        return FAILURE_EXIT;
    }
    free(oldpwd);
    return SUCCESS_EXIT;
}

static int cd_home(shell_t *shell)
{
    char *home_path = env_get_value(shell->env, "HOME=");

    if (home_path == NULL || home_path[0] == '\0') {
        (void)write(2, "cd: HOME not set\n", 17);
        return FAILURE_EXIT;
    }
    return cd_to(shell, home_path);
}

int my_cd(shell_t *shell, char **argv)
{
    size_t arg_nb = string_array_len(argv);
    char *oldpwd;

    if (arg_nb > 2) {
        (void)write(2, "cd: Too many arguments\n", 25);
        return FAILURE_EXIT;
    }
    if (arg_nb == 1)
        return cd_home(shell);
    if (my_strcmp(argv[1], "-") == 0) {
        oldpwd = env_get_value(shell->env, "OLDPWD=");
        if (!oldpwd) {
            (void)write(2, "cd: OLDPWD not set\n", 19);
            return FAILURE_EXIT;
        }
        return cd_to(shell, oldpwd);
    }
    return cd_to(shell, argv[1]);
}
