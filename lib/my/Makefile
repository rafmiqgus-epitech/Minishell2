NAME = libmy.a
CC = epiclang
CFLAGS =

SRC_DIR = .
OBJ_DIR = obj
HEADERS_DIR = .
LIB_OUT_DIR = ..
INCLUDE_DIR = ../../include

SRCS = $(SRC_DIR)/concat_params.c \
	$(SRC_DIR)/get_color.c \
	$(SRC_DIR)/my_advanced_sort_word_array.c \
	$(SRC_DIR)/my_char_islower.c \
	$(SRC_DIR)/my_char_isupper.c \
	$(SRC_DIR)/my_charlowcase.c \
	$(SRC_DIR)/my_charupcase.c \
	$(SRC_DIR)/my_compute_factorial_it.c \
	$(SRC_DIR)/my_compute_factorial_rec.c \
	$(SRC_DIR)/my_compute_power_it.c \
	$(SRC_DIR)/my_compute_power_rec.c \
	$(SRC_DIR)/my_compute_square_root.c \
	$(SRC_DIR)/my_evil_str.c \
	$(SRC_DIR)/my_find_prime_sup.c \
	$(SRC_DIR)/my_getnbr.c \
	$(SRC_DIR)/my_intlen.c \
	$(SRC_DIR)/my_is_prime.c \
	$(SRC_DIR)/my_isneg.c \
	$(SRC_DIR)/my_itoa.c \
	$(SRC_DIR)/my_params_to_array.c \
	$(SRC_DIR)/my_print_alpha.c \
	$(SRC_DIR)/my_print_comb.c \
	$(SRC_DIR)/my_print_comb2.c \
	$(SRC_DIR)/my_print_combn.c \
	$(SRC_DIR)/my_print_digits.c \
	$(SRC_DIR)/my_print_revalpha.c \
	$(SRC_DIR)/my_put_nbr.c \
	$(SRC_DIR)/my_putchar.c \
	$(SRC_DIR)/my_putnbr_base.c \
	$(SRC_DIR)/my_putstr.c \
	$(SRC_DIR)/my_realloc.c \
	$(SRC_DIR)/my_revstr.c \
	$(SRC_DIR)/my_show_param_array.c \
	$(SRC_DIR)/my_show_word_array.c \
	$(SRC_DIR)/my_showmem.c \
	$(SRC_DIR)/my_showstr.c \
	$(SRC_DIR)/my_sort_int_array.c \
	$(SRC_DIR)/my_sort_word_array.c \
	$(SRC_DIR)/my_str_isalpha.c \
	$(SRC_DIR)/my_str_islower.c \
	$(SRC_DIR)/my_str_isnum.c \
	$(SRC_DIR)/my_str_isprintable.c \
	$(SRC_DIR)/my_str_isupper.c \
	$(SRC_DIR)/my_split_words.c \
	$(SRC_DIR)/my_str_to_word_array.c \
	$(SRC_DIR)/my_strcapitalize.c \
	$(SRC_DIR)/my_strcat.c \
	$(SRC_DIR)/my_strcmp.c \
	$(SRC_DIR)/my_strcpy.c \
	$(SRC_DIR)/my_strdup.c \
	$(SRC_DIR)/my_strlen.c \
	$(SRC_DIR)/my_strlowcase.c \
	$(SRC_DIR)/my_strncat.c \
	$(SRC_DIR)/my_strncmp.c \
	$(SRC_DIR)/my_strncpy.c \
	$(SRC_DIR)/my_strstr.c \
	$(SRC_DIR)/my_strupcase.c \
	$(SRC_DIR)/my_swap.c \
	$(SRC_DIR)/print_error.c \
	$(SRC_DIR)/my_int_to_base.c \
	$(SRC_DIR)/my_ftoa.c \
	$(SRC_DIR)/ok_result_pattern_design.c \
	$(SRC_DIR)/err_result_pattern_design.c \
	$(SRC_DIR)/is_in_char.c \
	$(SRC_DIR)/my_append.c \
	$(SRC_DIR)/string_array.c \
	$(SRC_DIR)/my_memset.c \
	$(SRC_DIR)/put_llnbr.c \
	$(SRC_DIR)/type_handling.c \
	$(SRC_DIR)/file_to_mem.c \
	$(SRC_DIR)/random_utils.c \
	$(SRC_DIR)/my_printf/my_printf.c \
	$(SRC_DIR)/my_printf/length/length_handlers.c \
	$(SRC_DIR)/my_printf/length/default_length_handler.c \
	$(SRC_DIR)/my_printf/length/hh_length_handler.c \
	$(SRC_DIR)/my_printf/length/h_length_handler.c \
	$(SRC_DIR)/my_printf/length/j_length_handler.c \
	$(SRC_DIR)/my_printf/length/l_length_handler.c \
	$(SRC_DIR)/my_printf/length/ll_length_handler.c \
	$(SRC_DIR)/my_printf/length/l_maj_length_handler.c \
	$(SRC_DIR)/my_printf/length/z_length_handler.c \
	$(SRC_DIR)/my_printf/parsers/fill_buffer.c \
	$(SRC_DIR)/my_printf/parsers/apply_formatting.c \
	$(SRC_DIR)/my_printf/parsers/flags_parser.c \
	$(SRC_DIR)/my_printf/parsers/get_output_size.c \
	$(SRC_DIR)/my_printf/parsers/get_spec_content.c \
	$(SRC_DIR)/my_printf/parsers/get_spec_size.c \
	$(SRC_DIR)/my_printf/parsers/length_parser.c \
	$(SRC_DIR)/my_printf/parsers/precision_parser.c \
	$(SRC_DIR)/my_printf/parsers/specifier_parser.c \
	$(SRC_DIR)/my_printf/parsers/spec_parser.c \
	$(SRC_DIR)/my_printf/parsers/width_parser.c \
	$(SRC_DIR)/my_printf/precision/precision_utils.c \
	$(SRC_DIR)/my_printf/specifiers/get_specifier_content.c \
	$(SRC_DIR)/my_printf/specifiers/float_common.c \
	$(SRC_DIR)/my_printf/specifiers/float_fixed.c \
	$(SRC_DIR)/my_printf/specifiers/float_scientific.c \
	$(SRC_DIR)/my_printf/specifiers/float_general.c \
	$(SRC_DIR)/my_printf/specifiers/float_hex.c \
	$(SRC_DIR)/my_printf/specifiers/float_dispatch.c

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

HEADERS = $(SRC_DIR)/my.h \
	$(SRC_DIR)/my_macro_abs.h \
	$(SRC_DIR)/result_pattern_design.h

all: $(NAME) $(HEADERS:%=$(INCLUDE_DIR)/%)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	cp $(NAME) $(LIB_OUT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(INCLUDE_DIR)/%: %
	@mkdir -p $(INCLUDE_DIR)
	cp $< $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(SRC_DIR)/*.o
	rm -f $(NAME)

fclean:
	rm -f $(NAME)
	rm -f $(LIB_OUT_DIR)/$(NAME)
	rm -rf $(OBJ_DIR)
	rm -f $(SRC_DIR)/*.o
	rm -f $(HEADERS:%=$(INCLUDE_DIR)/%)

re: fclean all

.PHONY: all clean fclean re
