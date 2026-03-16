/*
** EPITECH PROJECT, 2025
** file_to_mem.c
** File description:
** functions to get the content of a file to memory
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

static ssize_t read_all(int fd, char *buf, size_t size)
{
    ssize_t total_read = 0;
    ssize_t r;

    while ((size_t)total_read < size) {
        r = read(fd, buf + total_read, size - (size_t)total_read);
        if (r < 0)
            return -1;
        if (r == 0)
            break;
        total_read += r;
    }
    return total_read;
}

static int open_and_stat(char const *filepath, struct stat *st)
{
    int fd = open(filepath, O_RDONLY);

    if (fd < 0) {
        perror("open");
        return -1;
    }
    if (stat(filepath, st) == -1 || !S_ISREG(st->st_mode)) {
        print_error("stat failed in open_and_stat()");
        close(fd);
        return -1;
    }
    return fd;
}

static char *read_fd_into_mem(int fd, size_t size)
{
    char *map = malloc(size + 1);
    ssize_t bytes_read;

    if (!map) {
        perror("malloc");
        close(fd);
        return NULL;
    }
    bytes_read = read_all(fd, map, size);
    close(fd);
    if (bytes_read != (ssize_t)size) {
        free(map);
        return NULL;
    }
    map[size] = '\0';
    return map;
}

char *load_file_in_mem(char const *filepath)
{
    struct stat st;
    int fd = open_and_stat(filepath, &st);

    if (fd < 0)
        return NULL;
    return read_fd_into_mem(fd, (size_t)st.st_size);
}
