#include "push_swap.h"

/* 第一个变成最后一个。
 * 1. 找到 last_node (尾节点)。
 * 2. 摘下 head: *stack 指向 head->next; 新 head->prev = NULL。
 * 3. 旧 head 断开连接: old_head->next = NULL。
 * 4. 接入尾部: last_node->next = old_head; old_head->prev = last_node。
 */
static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	t_stack_node	*old_head;

	if (!*stack || !(*stack)->next)
		return ;
	old_head = *stack;
	last_node = find_last(*stack);
	*stack = old_head->next;
	(*stack)->prev = NULL;
	old_head->next = NULL;
	last_node->next = old_head;
	old_head->prev = last_node;
}

/* RA: Rotate A。*/
void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (print)
		write(1, "ra\n", 3);
}

/* RB: Rotate B。*/
void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (print)
		write(1, "rb\n", 3);
}

/**
 * RR: Rotate Both。
 * 极重要的优化指令，能同时减少两个栈的成本。
 */
void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
}
