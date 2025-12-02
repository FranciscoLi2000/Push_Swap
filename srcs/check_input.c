#include "push_swap.h"

/* 检查字符串是否是有效的数字格式。
 *  * 1. 检查空字符串。
 *   * 2. 检查开头是否有 '+' 或 '-' (允许)。
 *    * 3. 检查后续字符是否全部为数字。
 *     * 4. 检查是否有单独的 '+' 或 '-' (无效输入)。
 *      */
static int	is_numeric(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/* 检查数值是否超出 INT 范围 (INT_MIN, INT_MAX)。
 * 1. 使用 long int 转换字符串，这是工程上的标准做法。
 * 2. 如果转换后的值不在 INT_MIN 和 INT_MAX 之间，则触发错误。
 */
static void	check_range(t_stack_node **a, char **args, bool is_split)
{
	long	num;
	int		i;

	i = 0;
	while (args[i])
	{
		num = (long)ft_atoi(args[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_exit(a, args, is_split);
		i++;
	}
}

/* 检查栈中是否有重复的数字。
 * 1. 遍历栈中的每个节点 (i)。
 * 2. 对每个节点 i，再次遍历后续节点 (j) 进行比较。
 * 3. 如果找到相同的值，触发错误。这是 O(N^2) 检查，对于 N=500 足够快。
 */
static void	check_duplicates(t_stack_node **a, char **args, bool is_split)
{
	t_stack_node	*i;
	t_stack_node	*j;

	i = *a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				error_exit(a, args, is_split);
			j = j->next;
		}
		i = i->next;
	}
}

/* 将有效数字转换为节点并添加到栈 A。
 * 假定你有一个辅助函数 node_add_back 来创建和链接新节点。
 */
static void	build_stack(t_stack_node **a, char **args, bool is_split)
{
	int	i;
	int	num;

	i = 0;
	while (args[i])
	{
		num = ft_atoi(args[i]);
		node_add_back(a, num);
		i++;
	}
	check_duplicates(a, args, is_split);
}

/* 验证所有命令行参数并准备构建栈 A。
 * 1. 对每个参数调用 is_numeric 进行字符验证。
 * 2. 检查数字范围 (check_range)。
 * 3. 如果验证通过，构建栈 A，并检查重复项。
 */
void	validate_and_build(t_stack_node **a, char **args, bool is_split)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!is_numeric(args[i]))
			error_exit(a, args, is_split);
		i++;
	}
	check_range(a, args, is_split);
	build_stack(a, args, is_split);
}
