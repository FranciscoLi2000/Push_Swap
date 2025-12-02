#include "push_swap.h"

/* 通用错误处理函数。
 * 1. 打印 "Error\n" 到标准错误输出 (stderr)。
 * 2. 释放所有已分配的内存 (如果 stack 非空)。
 * 3. 优雅地退出程序 (exit(1))。
 */
void	error_exit(t_stack_node **stack, char **args_array, bool is_split)
{
	write(2, "Error\n", 6);
	if (stack && *stack)
		free_stack(stack);
	if (args_array && is_split)
		free_args_array(args_array);
	exit(1);
}

/* 释放栈内存的辅助函数。
 * 遍历链表，逐个释放节点，直到栈为空。
 * 这是防止内存泄漏（Memory Leak）的关键。
 */
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*temp;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

/* 释放由 ft_split 创建的二维字符数组。
 * 如果输入参数是一个大字符串 ("1 2 3")，我们需要释放 ft_split 产生的子字符串数组。
 */
void	free_args_array(char **args_array)
{
	int	i;

	i = 0;
	while (args_array[i])
	{
		free(args_array[i]);
		i++;
	}
	free(args_array);
}
