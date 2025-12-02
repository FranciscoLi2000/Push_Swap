#include "push_swap.h"

/*
 * 最后一个变成第一个。
 * 1. 找到 last (尾) 和 second_last (倒数第二)。
 * 2. 倒数第二变成新尾: second_last->next = NULL。
 * 3. 接入头部: last->next = *stack; (*stack)->prev = last。
 * 4. 更新 head: *stack = last; last->prev = NULL。
 */
static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}

/* RRA: Reverse Rotate A。*/
void	rra(t_stack_node **a, bool print)
{
	rev_rotate(a);
	if (print)
		write(1, "rra\n", 4);
}

/* RRB: Reverse Rotate B。*/
void	rrb(t_stack_node **b, bool print)
{
	rev_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
}

/* RRR: Reverse Rotate Both。
 * 也是重要的优化指令。
 */
void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
}
