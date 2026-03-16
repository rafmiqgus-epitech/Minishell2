NAME = mysh
CC = epiclang
CFLAGS = -Wall -Wextra -Iinclude -g3
LDFLAGS = -L./lib -lmy -lncurses

SRCS_DIR = src
SRCS = $(SRCS_DIR)/main.c \
	   $(SRCS_DIR)/builtins/run_builtin.c \
	   $(SRCS_DIR)/builtins/exit.c \
	   $(SRCS_DIR)/builtins/cd.c \
	   $(SRCS_DIR)/builtins/setenv.c \
	   $(SRCS_DIR)/builtins/unsetenv.c \
	   $(SRCS_DIR)/builtins/env.c \
	   $(SRCS_DIR)/exec/run_command.c \
	   $(SRCS_DIR)/exec/resolve_path.c \
	   $(SRCS_DIR)/exec/run_external.c \
	   $(SRCS_DIR)/env/pwd.c \
	   $(SRCS_DIR)/shell/loop.c \
	   $(SRCS_DIR)/shell/init.c

OBJS_DIR = obj
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

LIB_DIR = lib/my
LIB = libmy.a

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c include/*.h
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

tests_run: all
	$(MAKE) -C tests re
	./tests/mysh_tests

.PHONY: all clean fclean re tests_run
