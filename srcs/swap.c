#include "push_swap.h"

/* 交换栈顶的两个节点。
 * 1. 检查是否有足够的节点 (至少 2 个)。
 * 2. 定义 first 和 second 节点。
 * 3. 调整指针: first->next 指向 second->next; second->prev 指向 NULL。
 * 4. 修复链条断口: if (first->next) first->next->prev = first。
 * 5. 互连: second->next = first; first->prev = second。
 * 6. 更新头指针: *head = second。
 */
static void	swap(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
}

/* SA: Swap A (交换 A 栈顶两元素)。*/
void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
}

/* SB: Swap B (交换 B 栈顶两元素)。*/
void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (print)
		write(1, "sb\n", 3);
}

/* SS: Swap Both (同时交换 A 和 B)。
 * 这是一个组合指令，通常用于优化。
 */
void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
}
