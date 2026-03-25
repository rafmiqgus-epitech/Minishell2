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
	   $(SRCS_DIR)/exec/redirections.c \
	   $(SRCS_DIR)/env/pwd.c \
	   $(SRCS_DIR)/shell/loop.c \
	   $(SRCS_DIR)/shell/init.c \
	   $(SRCS_DIR)/parser/tokenize.c \
	   $(SRCS_DIR)/parser/parse_command.c \
	   $(SRCS_DIR)/parser/parse_utils.c \
	   $(SRCS_DIR)/parser/parse_create.c \
	   $(SRCS_DIR)/parser/parse_append.c \
	   $(SRCS_DIR)/parser/parse_free.c

BUILD_DIR = build
OBJS_DIR = $(BUILD_DIR)/obj
DEPS_DIR = $(BUILD_DIR)/dep
BIN_DIR = $(BUILD_DIR)/bin
TARGET = $(BIN_DIR)/$(NAME)
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
DEPS = $(SRCS:$(SRCS_DIR)/%.c=$(DEPS_DIR)/%.d)

LIB_DIR = lib/my
LIB = libmy.a

all: $(NAME)

$(NAME): $(TARGET)
	ln -sf $(TARGET) $(NAME)

$(TARGET): $(LIB) $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(LIB):
	$(MAKE) -C $(LIB_DIR)


$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c include/*.h
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(DEPS_DIR)/$*.d)
	$(CC) $(CFLAGS) -MMD -MP -MF $(DEPS_DIR)/$*.d -MT $@ -c $< -o $@


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

compdb:
	@mkdir -p $(BUILD_DIR)
	bear --output $(BUILD_DIR)/compile_commands.json -- $(MAKE) -B $(OBJS)

.PHONY: all clean fclean re tests_run
