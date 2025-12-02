#include "push_swap.h"

static void	push_swap(t_stack_node **a)
{
	t_stack_node	*b;
	int			len;

	b = NULL;
	len = stack_len(*a);
	if (len == 2)
		sa(a, true);
	else if (len == 3)
		sort_three(a);
	else
		sort_stacks(a, &b);
	free_stack(a);
	free_stack(&b);
}

/* 程序主入口。负责处理输入格式和流程调度。
 * 1. 处理单个大字符串输入 (例如: ./ps "1 2 3")。使用 ft_split。
 * 2. 处理多参数输入 (例如: ./ps 1 2 3)。直接使用 argv+1。
 * 3. 调用 validate_and_build 执行所有错误检查并构建栈 A。
 * 4. 如果栈已经有序或节点少于 2 个，直接退出。
 */
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	char			**args;
	bool			is_split;

	a = NULL;
	is_split = false;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		is_split = true;
	}
	else
		args = argv + 1;
	validate_and_build(&a, args, is_split);
	if (is_split)
		free_args_array(args);
	if (stack_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	push_swap(&a);
	return (0);
}
