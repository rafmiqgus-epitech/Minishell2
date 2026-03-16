/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my lib
*/

#ifndef MY_H_
    #define MY_H_
    #include <stddef.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include "result_pattern_design.h"

struct info_param
{
    int length;
    char *str;
    char *copy;
    char **word_array;
};

int my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_it(int nb, int power);
int my_compute_power_rec(int nb, int power);
int my_copute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_putnbr_base(int nbr, char const *base);
int validate_base(char const *base);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char *const *tab);
char *my_strdup(char const *str);
char **my_str_to_word_array(char const *str);
char **my_split_words(char const *str, char const *delimiters);
char **my_str_to_word_array_with_delimiters(char const *str,
    char const *delimiters);
struct info_param *my_params_to_array(int argc, char **argv);
int my_show_param_array(struct info_param const *par);
char *concat_params(int argc, char **argv);
int my_compute_factorial_it(int nb);
int my_compute_factorial_rec(int nb);
int my_compute_square_root(int nb);
char *my_evil_str(char *str);
int my_print_alpha(void);
int my_print_comb(void);
int my_print_comb2(void);
int my_print_combn(int n);
int my_print_digits(void);
int my_print_revalpha(void);
int get_color(unsigned char red, unsigned char green, unsigned char blue);
int my_showstr(char const *str);
struct info_param *my_params_to_array(int ac, char **av);
int print_error(const char *err_msg);
int my_char_isupper(char c);
int my_char_islower(char c);
char my_charupcase(char c);
char my_charlowcase(char c);
void *my_realloc(void *ptr, size_t new_size);
char *my_itoa(int nb);
int mini_printf(const char *format, ...);
int my_printf(const char *format, ...);
size_t my_intlen(int nb);
char *my_int_to_base(unsigned long long nbr, char const *base);
char *my_ftoa(float nb, int precision);
char *my_dtoa_scientific(double nb, int precision, int uppercase);
char *my_dtoa_hex(double nb, int precision, int uppercase);
bool is_in_char(char c, const char *set);
result_string_array_t my_append(char ***array, const char *str);
void *my_memset(void *s, int c, size_t n);
void put_llunbr(unsigned long long value);
void put_llnbr(long long value);
bool is_int_str(const char *str);
bool is_int_char(char c);
int str_to_int(const char *str);
char *load_file_in_mem(char const *filepath);
int rand_int(int min, int max);
float rand_float(float min, float max);
bool rand_bool(void);
size_t string_array_len(char **array);
void free_string_array(char **array);
char **dup_string_array(char **array);

#endif
