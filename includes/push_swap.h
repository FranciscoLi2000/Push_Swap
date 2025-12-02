#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int				main(int argc, char **argv);

/* 错误处理与内存管理 (error_handler.c) --- */
void			error_exit(t_stack_node **s, char **args, bool is_split);
void			free_stack(t_stack_node **stack);
void			free_args_array(char **args_array);

/* 解析与栈初始化 (check_input.c & stack_utils_b.c) --- */
void			validate_and_build(t_stack_node **a, char **args, bool is_split);
void			node_add_back(t_stack_node **stack, int value);
t_stack_node	*find_last(t_stack_node *stack);

/* 指令集 (push.c, swap.c, rotate.c, rev_rotate.c) --- */
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **a, t_stack_node **b, bool print);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

/* 算法与工具函数 (sort_turk.c, algo_logic.c, stack_utils_a.c) --- */
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
void			current_index(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);
void			rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
void			rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);

void			cost_analysis(t_stack_node *a, t_stack_node *b);

#endif
