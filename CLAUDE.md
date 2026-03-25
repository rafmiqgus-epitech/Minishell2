# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is **Minishell2**, an Epitech project to build a UNIX command interpreter based on TCSH. It extends Minishell1 (basic shell with builtins) by adding:
- Semicolons (`;`) for sequential command execution
- Pipes (`|`) to connect command stdout to stdin
- Redirections: `>` (overwrite), `<` (input), `>>` (append), `<<` (heredoc)

**Priority management** between operators is a key requirement.

## Build Commands

```bash
make              # Build mysh executable (creates ./mysh symlink to build/bin/mysh)
make clean        # Remove object files
make fclean       # Full clean including binary and library
make re           # Clean rebuild
make tests_run    # Run Criterion test suite
make compdb       # Generate compile_commands.json for IDE support
```

**Compiler**: `epiclang` (Epitech's LLVM-based compiler) with flags `-Wall -Wextra -Iinclude -g3`

## Running the Shell

```bash
./mysh              # Interactive mode with prompt
echo "ls" | ./mysh  # Non-interactive mode (no prompt) - this is how tests are run
```

## Testing

Tests use the Criterion framework and are located in `tests/`:
```bash
cd tests && make && make run    # Build and run tests from tests directory
make tests_run                   # Or run from project root
```

Tests execute `./mysh` so build the project first.

## Architecture

**Core Data Structure** (`include/shell.h`):
```c
typedef struct {
    char **env;        // Mutable copy of environment
    int last_status;   // Exit status of last command
    char *line;        // Input buffer (getline managed)
    pid_t last_pid;    // PID of last spawned process
} shell_t;
```

**Source Organization**:
- `src/shell/` - Shell initialization (`init.c`) and main loop (`loop.c`)
- `src/builtins/` - Built-in commands (exit, cd, env, setenv, unsetenv) with dispatcher in `run_builtin.c`
- `src/exec/` - External command execution: `run_command.c` (dispatcher), `run_external.c` (fork/exec), `resolve_path.c` (PATH lookup)
- `src/env/` - Environment variable management (`pwd.c` handles get/set/PWD sync)
- `src/parser/` - Tokenizer for parsing input into tokens

**Execution Flow**:
1. `main.c` → `shell_init()` duplicates envp
2. `shell_loop()` reads input, displays prompt if interactive
3. `run_command()` dispatches to builtin or external execution
4. External commands: `resolve_path()` → `fork()` → `execve()`

## Built-in Commands

| Command | Behavior |
|---------|----------|
| `exit` | Exit with last command's status |
| `cd [dir]` | Change directory; `cd -` goes to OLDPWD; syncs PWD/OLDPWD |
| `env` | Print environment variables (no arguments) |
| `setenv VAR [val]` | Set/create environment variable |
| `unsetenv VAR` | Remove environment variable (no `*` wildcard) |

## Authorized Functions

`malloc`, `free`, `exit`, `opendir`, `readdir`, `closedir`, `getcwd`, `chdir`, `fork`, `stat`, `lstat`, `fstat`, `open`, `close`, `getline`, `strtok`, `strtok_r`, `read`, `write`, `execve`, `access`, `isatty`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `kill`, `getpid`, `strerror`, `perror`, `strsignal`, `pipe`, `dup`, `dup2`

## Key Conventions

- Error messages to stderr, exit code 84 on error (0 on success)
- Error messages should match TCSH behavior
- Shell exit status must equal the last executed command's exit status
- Environment variables stored as `"KEY=VALUE"` strings in `shell->env`
- Child exit codes: normal exits use `WEXITSTATUS()`, signals map to `128 + signal_number`
- Custom library `lib/my/libmy.a` provides string utilities (`dup_string_array`, `free_string_array`, etc.)

## Minishell2 Features to Implement

1. **Semicolons (`;`)**: Execute commands sequentially
   - `ls -l; pwd` runs `ls -l` then `pwd`

2. **Pipes (`|`)**: Connect stdout of left command to stdin of right command
   - `ls | wc -l` pipes ls output to wc
   - Multiple pipes: `ls | cat | wc -c`

3. **Redirections**:
   - `>` output to file (overwrite)
   - `>>` output to file (append)
   - `<` input from file
   - `<<` heredoc (read until delimiter)

4. **Bonus**: `2>&1` style stderr redirection
