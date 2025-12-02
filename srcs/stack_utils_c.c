#include "push_swap.h"

/* 查找链表的最后一个节点。
 * 这是一个极其常用的辅助函数，用于 append 节点或计算 reverse rotate。
 * 逻辑简单：只要 next 不为空，就一直往后走。
 */
t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/* 创建新节点并添加到栈尾。
 * 与 libft 不同，这里直接处理 int value，并负责初始化所有元数据(cost, target等)为0/NULL。
 * 关键点：
 * 1. Malloc 分配内存。
 * 2. 如果栈为空，新节点就是头节点。
 * 3. 如果栈不为空，找到尾节点，将尾节点的 next 指向新节点，新节点的 prev 指向尾节点。
 * 4. 这是一个典型的双向链表插入操作。
 */
void	node_add_back(t_stack_node **stack, int value)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = value;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
