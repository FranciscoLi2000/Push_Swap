#include "push_swap.h"

/* 针对 3 个节点的硬编码排序。
 * 这是一个常数时间复杂度的操作，用于处理递归的边界或小数据集。
 * 逻辑：
 * 1. 找到最大值节点 (biggest_node)。
 * 2. 如果最大值在栈顶 -> ra (转到底部)。
 * 3. 如果最大值在中间 -> rra (反向转到底部)。
 * 4. 此时最大值已在底部。检查前两个数，如果顺序不对(a > b) -> sa。
 */
void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, true);
	else if ((*a)->next == biggest_node)
		rra(a, true);
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}
