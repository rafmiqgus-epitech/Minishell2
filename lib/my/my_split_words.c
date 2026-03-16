/*
** EPITECH PROJECT, 2026
** my_split_words.c
** File description:
** split string into words using optional delimiters
*/

#include "my.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

static bool is_alpha(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

static bool is_delimiter(char c, char const *delimiters)
{
    if (delimiters == NULL || delimiters[0] == '\0')
        return !is_alpha(c);
    return is_in_char(c, delimiters);
}

static int count_words(char const *str, char const *delimiters)
{
    int count = 0;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (is_delimiter(str[i], delimiters))
            continue;
        if (i == 0 || is_delimiter(str[i - 1], delimiters))
            count++;
    }
    return count;
}

static char *extract_word(char const *str, int start, int end)
{
    char *word = malloc((end - start + 1) * sizeof(char));

    if (word == NULL)
        return NULL;
    for (int i = start; i < end; ++i)
        word[i - start] = str[i];
    word[end - start] = '\0';
    return word;
}

static void free_words(char **words, int words_count)
{
    for (int i = 0; i < words_count; ++i)
        free(words[i]);
    free(words);
}

static int store_word(char const *str, int start, int end, char **slot)
{
    *slot = extract_word(str, start, end);
    if (*slot == NULL)
        return 84;
    return 0;
}

static int fill_words(char const *str, char const *delimiters, char **words)
{
    int start = -1;
    int words_count = 0;

    for (int i = 0;; ++i) {
        if (str[i] != '\0' && !is_delimiter(str[i], delimiters)) {
            start = (start == -1) ? i : start;
            continue;
        }
        if (start != -1 && store_word(str, start, i, &words[words_count])) {
            free_words(words, words_count);
            return 84;
        }
        if (start != -1)
            words_count++;
        start = -1;
        if (str[i] == '\0')
            break;
    }
    words[words_count] = NULL;
    return 0;
}

char **my_split_words(char const *str, char const *delimiters)
{
    char **words;
    int words_count;

    if (str == NULL)
        return NULL;
    words_count = count_words(str, delimiters);
    words = malloc((words_count + 1) * sizeof(char *));
    if (words == NULL)
        return NULL;
    if (fill_words(str, delimiters, words) != 0)
        return NULL;
    return words;
}
