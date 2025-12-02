# --- Variables ---
NAME			= push_swap
CC			= cc
CFLAGS			= -Wall -Wextra -Werror -g
RM			= rm -f

# --- Directories ---
SRCS_DIR		= srcs/
OBJS_DIR		= .objs/
INCLUDES		= includes/
LIBFT_DIR		= libft/

# --- Source and Object Files ---
SRCS			= algo_logic.c algo_utils.c check_input.c main.c \
			  rev_rotate.c sort_tiny.c stack_utils_a.c stack_utils_c.c \
			  algo_logic_a.c algo_utils_opt.c error_handler.c push.c \
			  rotate.c sort_turk.c stack_utils_b.c swap.c

OBJS			= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

# --- Libft Dependency ---
LIBFT_LIB	= $(LIBFT_DIR)libft.a

# --- Targets ---
# Default target: builds libft and the main program
all: $(LIBFT_LIB) $(OBJS_DIR) $(NAME)

# Rule to create the object directory if it doesn't exist
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

# Rule to link the final executable
$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

# Rule to compile source files to object files
# Uses the push_swap.h header file in compilation
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES)push_swap.h
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIBFT_DIR) -c $< -o $@

# Rule to build the libft static library
$(LIBFT_LIB):
	make -C $(LIBFT_DIR) all

# Removes object files
clean:
	$(RM) -r $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean

# Removes object files, libft.a, and the executable
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

# Rebuilds the entire project
re: fclean all

# Phony targets to prevent conflicts with file names
.PHONY: all clean fclean re $(LIBFT_LIB)
