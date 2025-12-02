#include "push_swap.h"

/* 为 A 中的每个节点找到 B 中的目标节点 (Target Node)。
 * 规则：A 的节点应该放在 B 中"小于"它的"最大"值的上面。(这样 B 栈保持降序排列)。
 * 举例: A node = 5. B = {8, 4, 2}. 
 * 小于 5 的有 4 和 2。其中 4 最大。target = 4。
 * 如果 B 中没有比 A 小的数 (A node 是新的最小值)，target 是 B 的最大值。
 */
static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value && current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

/**
 * 初始化 A 到 B 的移动数据。
 * 这里的逻辑和 init_nodes_b 完全对称，只是调用了 set_target_a。
 */
void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis(a, b);
	set_cheapest(a);
}

/* 执行 A 到 B 的移动。
 * 逻辑与 move_b_to_a 几乎一致，只是方向相反。
 *  1. 取出 cheapest 节点。
 *  2. 如果 cheapest 和 target 都在上/下半区，双旋优化。
 *  3. 旋转 A 让 cheapest 到顶。
 *  4. 旋转 B 让 target 到顶。
 *  5. pb。
 */
void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}
