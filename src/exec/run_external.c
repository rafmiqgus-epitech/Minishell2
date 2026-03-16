/*
** EPITECH PROJECT, 2026
** run_external.c
** File description:
** fork/execve/wait + status propagation
*/

#include "../../include/shell.h"
#include "../../include/mysh.h"
#include "../../include/my.h"
#include "../../include/exec.h"

#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

static void print_execve_error(char *command, int err)
{
    print_error(command);
    print_error(": ");
    if (err == ENOEXEC)
        print_error("Exec format error. Binary file not executable.\n");
    if (err == EACCES)
        print_error("Permission denied.\n");
    if (err == ENOENT)
        print_error("No such file or directory.\n");
    if (err == EISDIR)
        print_error("Is a directory.\n");
    if (err != ENOEXEC && err != EACCES && err != ENOENT && err != EISDIR) {
        print_error(strerror(err));
        print_error("\n");
    }
}

static int handle_child_segfault_status(int status)
{
    int sig = WTERMSIG(status);

    if (sig == SIGSEGV)
        print_error("Segmentation fault");
    if (sig == SIGFPE)
        print_error("Floating exception");
    if (sig == SIGABRT)
        print_error("Aborted");
    if (sig == SIGILL)
        print_error("Illegal instruction");
    if (sig == SIGBUS)
        print_error("Bus error");
#ifdef WCOREDUMP
    if (WCOREDUMP(status))
        print_error(" (core dumped)");
#endif
    print_error("\n");
    return 128 + WTERMSIG(status);
}

static int handle_child_status(int status)
{
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    if (WIFSIGNALED(status)) {
        return handle_child_segfault_status(status);
    }
    return 1;
}

static int spawn_and_wait(shell_t *shell, char *exe_path,
    char **argv, char **env)
{
    pid_t child_pid = fork();
    int code = 0;
    int err = 0;

    if (child_pid < 0) {
        print_error("fork failed\n");
        free(exe_path);
        return FAILURE_EXIT;
    }
    if (child_pid == 0) {
        execve(exe_path, argv, env);
        err = errno;
        print_execve_error(argv[0], err);
        free(exe_path);
        exit(FAILURE_EXIT);
    }
    waitpid(child_pid, &code, 0);
    shell->last_status = handle_child_status(code);
    free(exe_path);
    return SUCCESS_EXIT;
}

int run_external(shell_t *shell, char **argv)
{
    bool from_path = !contains_slash(argv[0]);
    char *exe_path = build_exec_path(shell->env, argv[0]);

    if (from_path && find_path_value(shell->env) == NULL)
        print_path_not_set();
    if (validate_exec_target(argv[0], exe_path, from_path) != SUCCESS_EXIT) {
        free(exe_path);
        return FAILURE_EXIT;
    }
    return spawn_and_wait(shell, exe_path, argv, shell->env);
}
