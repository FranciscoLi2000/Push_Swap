#include "push_swap.h"

/* 将 src 栈顶的节点摘下，接入到 dest 栈顶。
 * 1. 如果 src 为空，直接返回。
 * 2. 摘下 push_node: src 指针下移。如果 src 还有节点，更新其 prev 为 NULL。
 * 3. 接入 dest: push_node 指向 dest 原头节点。
 * 4. 如果 dest 非空，更新原头节点的 prev。
 * 5. 更新 dest 头指针指向 push_node。
 */
static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

/**
 * PA: Push A (把 B 的栈顶推给 A)。
 * 调用通用 push 函数，若 print 为 true，则打印指令。
 */
void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (print)
		write(1, "pa\n", 3);
}

/**
 * PB: Push B (把 A 的栈顶推给 B)。
 * 调用通用 push 函数，若 print 为 true，则打印指令。
 */
void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (print)
		write(1, "pb\n", 3);
}
