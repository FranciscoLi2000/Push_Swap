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
SRCS			= append_node.c current_index.c free_stack.c move_a_to_b.c \
			  reverse_rotate.c set_cheapest.c stack_init.c check_duplicates.c \
			  find_last.c ft_atol.c move_b_to_a.c rotate.c set_target_a.c \
			  stack_len.c check_input.c find_max.c ft_stack_new.c normalize_stack.c \
			  rotate_a_to_target.c sort_small.c stack_sorted.c check_overflow.c \
			  find_min.c main.c push.c rotate_b_to_top.c sort_stacks.c swap.c \
			  cost_analysis_a.c free_errors.c min_on_top.c rev_rotate_both.c \
			  rotate_both.c sort_three.c

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
