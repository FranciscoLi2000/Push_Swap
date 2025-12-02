#include "push_swap.h"

/* 双旋优化 (RR)。
 *  * 当 cheapest 节点和 target 节点都在栈的上半部分时，
 *   * 我们可以同时旋转 A 和 B，直到其中一个到达栈顶。
 *    * 剩下的那个再单独旋转。
 *     */
void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

/* 双反旋优化 (RRR)。
 *  * 当 cheapest 节点和 target 节点都在栈的下半部分时，
 *   * 同时反向旋转 A 和 B。
 *    */
void	rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}
